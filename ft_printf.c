/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:22:45 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/10 15:42:01 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static	void	check_hexa(const char s, int *count, va_list value)
{
	if (s == 'p')
	{
		*count += ft_putstr("0x");
		*count += putnbr_unsig(va_arg(value, unsigned long long));
	}
	else if (s == 'x' || s == 'X')
	{
		if (s == 'x')
			*count += nbr_int(va_arg(value, unsigned int), "0123456789abcdef");
		else
			*count += nbr_int(va_arg(value, unsigned int), "0123456789ABCDEF");
	}
}

static void	check(const char s, int *count, va_list value)
{
	if (s == 'u')
		*count += nbr_int(va_arg(value, unsigned int), "0123456789");
	else if (s == 'c')
		*count += print_char(va_arg(value, int));
	else if (s == 'i' || s == 'd')
		*count += ft_putnbr_base(va_arg(value, int), "0123456789");
	else if (s == 's')
		*count += (int)ft_putstr(va_arg(value, char *));
	else if (check_letter("xXp", s))
		check_hexa(s, count, value);
}

int	ft_printf(char const *string, ...)
{
	va_list	vargs;
	int		count;

	count = 0;
	va_start(vargs, string);
	while (*string)
	{
		if (*string == '%')
		{
			if (check_letter("cspdiuxX",*(string + 1)))
				check(*(string + 1), &count, vargs);
			else
				count += print_char(*(string + 1));
			string++;
		}
		else
			count += print_char(*string);
		string++;
	}
	va_end(vargs);
	return (count);
}
