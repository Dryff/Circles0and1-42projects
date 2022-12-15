/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:07:31 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/15 20:38:56 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

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
	while (i < data->nbrs_size)
	{
		if (nb == data->nbrs[i])
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
