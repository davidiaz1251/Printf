/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:23:43 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/12 11:26:21 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/************************* HEADERS *****************/
# include <stdarg.h>
# include "Libft/libft.h"
/************** PROTOTYPES FUNCTION ****************/
int	ft_printf(char const *string, ...);
int	print_char(const char s);
int	ft_putstr(char *s);
int	putnbr(unsigned long long nbr, const char *base);
int	ft_putnbr_base(int nbr, const char *base);
#endif