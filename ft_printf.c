/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:22:45 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/09 13:49:29 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static int	print_char(const char s)
{
	ft_putchar_fd(s, 1);
	return (1);
}

static size_t	check_letter(char const *set, char const c)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static char const	*check(const char *s, int *count, void *value)
{
	if (*(s + 1) == 's')
	{
		ft_putstr_fd((char *)value, 1);
		*count += (int)ft_strlen((char *)value);
	}
	else if (*(s + 1) == 'c')
		*count += print_char((char)value);
	else if (*(s + 1) == 'i' || *(s + 1) == 'd')
		*count += putnbr_base_fd((int)value, "0123456789");
	else if (*(s + 1) == 'u')
		*count += putnbr_base_fd_unsigned((unsigned int)value, "0123456789");
	else if (*(s + 1) == 'p')
	{
		ft_putstr_fd("0x", 1);
		*count += 2;
		*count += ft_putnbr_ptr((unsigned long long)value, "0123456789abcdef");
	}
	else if (*(s + 1) == 'x' || *(s + 1) == 'X')
	{
		if (*(s + 1) == 'x')
			*count += putnbr_base_fd((int)value, "0123456789abcdef");
		else
			*count += putnbr_base_fd((int)value, "0123456789ABCDEF");
	}
	return (s += 1);
}

int	ft_printf(char const *string, ...)
{
	va_list	vargs;
	int		count;

	count = 0;
	va_start(vargs, string);
	while (*string)
	{
		if (*string == '%' && *(string + 1) == 's')
			string = check(string, &count, va_arg(vargs, char *));
		else if (*string == '%' && check_letter("cdixX",*(string + 1)))
			string = check(string, &count, va_arg(vargs, int *));
		else if (*string == '%' && *(string + 1) == 'u')
			string = check(string, &count, va_arg(vargs, unsigned int *));
		else if (*string == '%' && *(string + 1) == 'p')
			string = check(string, &count, va_arg(vargs, unsigned long long *));
		else if (*string == '%' && *(string + 1) == '%')
		{
			count += print_char(*string);
			string++;
		}
		else
			count += print_char(*string);
		string++;
	}
	va_end(vargs);
	return (count);
}
