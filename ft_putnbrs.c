/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:26:02 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/11 11:08:27 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(unsigned long long nbr, const char *base)
{
	int		base_len;
	int		count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < (unsigned long long)base_len)
	{
		ft_putchar_fd(*(base + (size_t)nbr % base_len), 1);
		count++;
	}
	else
	{
		count += putnbr(nbr / base_len, base);
		count += putnbr(nbr % base_len, base);
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
