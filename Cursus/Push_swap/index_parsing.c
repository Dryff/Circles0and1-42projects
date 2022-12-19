/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:07:31 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/19 12:15:41 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	general_sort(t_struct *data)
{
	if (data->a_size < 2)
		return (0);
	else if (data->a_size == 3)
		return (sort_three(data), 0);
	else if (data->a_size == 5)
		return (sort_five(data), 0);
	else
	{
		binary_index_parse(data);
		radix_sort(data);	
	}
	return (0);
}

static	long	dec_to_bin(long n)
{
	long	bin;
	long	dec;
	long	i;

	bin = 0;
	dec = n;
	i = 1;
	while (dec > 0)
	{
		bin += (dec % 2) * i;
		dec /= 2;
		i *= 10;
	}
	return (bin);
}

static	int	get_index_sorted(t_struct *data, int nb)
{
	int	i;

	i = 0;
	while (i < data->nb_size)
	{
		if (nb == data->nb_sort[i])
			return (i);
		i++;
	}
	return (0);
}

void	binary_index_parse(t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->a_size)
	{
		data->a_stack[i] = dec_to_bin(get_index_sorted(data, data->a_stack[i]));
		i++;
	}
}
