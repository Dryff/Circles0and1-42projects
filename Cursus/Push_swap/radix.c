/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:30:29 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/15 20:59:41 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	is_sort(t_struct *data)
{
	int	i;

	if (data->b_size)
		return (0);
	i = 0;
	while (++i < data->a_size)
		if (data->a_stack[i] <= data->a_stack[i - 1])
			return (0);
	return (1);
}

static	int	get_index(int nb, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		nb = nb / 10;
		i++;
	}
	return (nb % 10);
}

void	radix_sort(t_struct *data)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (!is_sort(data))
	{
		while (i < data->nbrs_size)
		{
			if (!get_index(data->a_stack[0], index))
				pb(data);
			else
				ra(data);
			i++;
		}
		i = 0;						
		while (data->b_size > 0)
			pa(data);
		index++;
	}
}
