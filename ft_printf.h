/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:23:43 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/10/09 12:18:42 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
/************************* HEADERS *****************/
# include <stdarg.h>
# include "Libft/libft.h"
/************** PROTOTYPES FUNCTION ****************/
int	ft_printf(char const *string, ...);
int	ft_putnbr_ptr(unsigned long long nbr, const char *base);
int	putnbr_base_fd(int nbr, const char *base);
int	putnbr_base_fd_unsigned(unsigned int nbr, const char *base);
#endif