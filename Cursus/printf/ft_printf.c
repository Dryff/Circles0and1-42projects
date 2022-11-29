/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:47:31 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/23 11:26:57 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_next_char_count(char *str, int i, va_list args)
{
	if (str[i] == 'c')
		return (ft_putchar_int(va_arg(args, int)));
	else if (str[i] == 's')
		return (ft_putstr_int(va_arg(args, char *)));
	else if (str[i] == 'p')
	{
		write(1, "0x", 2);
		return (print_hexa_adress(va_arg(args, unsigned long long), 0));
	}
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_int(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_putnbr_u_int(va_arg(args, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (print_hexa(va_arg(args, unsigned int), str[i]));
	else if (str[i] == '%')
		return (ft_putchar_int('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	if (write(1, 0, 0) != 0)
		return (va_end(args), -1);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += get_next_char_count((char *)str, ++i, args);
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	return (va_end(args), len);
}
