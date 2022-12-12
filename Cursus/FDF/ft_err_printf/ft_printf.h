/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:49:01 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/08 14:52:07 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int							ft_err_printf(const char *str, ...);
int							ft_putstr_int(char *s);
int							ft_putchar_int(int c);
int							ft_len(int n);
int							ft_putnbr_int(int n);
int							ft_putnbr_u_int(unsigned int n);
int							print_hexa_adress(unsigned long long n, char caps);
unsigned int				print_hexa(long n, char caps);

#endif