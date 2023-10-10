/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:26:02 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/10 15:41:47 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_unsig(unsigned long long nbr)
{
	int		base_len;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	count = 0;
	if (nbr < (unsigned long long)base_len)
	{
		ft_putchar_fd(*(base + (size_t)nbr % base_len), 1);
		count++;
	}
	else
	{
		count += putnbr_unsig(nbr / base_len);
		count += putnbr_unsig(nbr % base_len);
	}
	return (count);
}

int	nbr_int(unsigned int nbr, const char *base)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < (unsigned int)base_len)
	{
		ft_putchar_fd(*(base + (size_t)nbr % base_len), 1);
		count++;
	}
	else
	{
		count += nbr_int(nbr / base_len, base);
		count += nbr_int(nbr % base_len, base);
	}
	return (count);
}

int	ft_putnbr_base(int nbr, const char *base)
{
	int				base_len;
	long long int	nb;
	int				count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nb = -((long long int)nbr);
	}
	else
		nb = (long long int)nbr;
	if (nb < base_len)
	{
		ft_putchar_fd(*(base + (size_t)nb % base_len), 1);
		count++;
	}
	else
	{
		count += ft_putnbr_base(nb / base_len, base);
		count += ft_putnbr_base(nb % base_len, base);
	}
	return (count);
}
