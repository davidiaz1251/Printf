/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:26:02 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/09 12:45:12 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ptr(unsigned long long nbr, const char *base)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr < (unsigned long long)base_len)
	{
		ft_putchar_fd(*(base + (size_t)nbr % base_len), 1);
		count++;
	}
	else
	{
		count += ft_putnbr_ptr(nbr / base_len, base);
		count += ft_putnbr_ptr(nbr % base_len, base);
	}
	return (count);
}

int	putnbr_base_fd(int nbr, const char *base)
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
		count += putnbr_base_fd(nb / base_len, base);
		count += putnbr_base_fd(nb % base_len, base);
	}
	return (count);
}

int	putnbr_base_fd_unsigned(unsigned int nbr, const char *base)
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
		count += putnbr_base_fd_unsigned(nb / base_len, base);
		count += putnbr_base_fd_unsigned(nb % base_len, base);
	}
	return (count);
}
