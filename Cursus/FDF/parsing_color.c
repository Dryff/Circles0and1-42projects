/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:16:37 by colas             #+#    #+#             */
/*   Updated: 2023/01/09 10:29:01 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int	base_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ahextoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r' )
		i++;
	nb = 0;
	while (str[i])
	{
		nb = nb * 16 + base_pos(str[i], "0123456789ABCDEF");
		i++;
	}
	return (nb);
}

int	ft_split_hex_color(const char *s, int i)
{
	char	*str;
	int		j;
	int		count;

	j = i;
	count = 0;
	while (s[j] && s[j - 1] != ',')
	{
		if (s[j] == ' ' || s[j] == '\n')
			return (0xFFFFFF);
		j++;
	}
	if (s[j] == 0)
		return (0);
	while (s[j] && s[j++] != ' ')
		count++;
	str = malloc(count * sizeof(char));
	if (!str)
		return (0);
	i+=4;
	j = 0;
	while (s[i] != ' ')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (ahextoi(str));
}