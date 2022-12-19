/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:30:29 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/19 17:07:17 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	is_sort(t_struct *ps)
{
	int	i;

	if (ps->b_size)
		return (0);
	i = 0;
	while (++i < ps->a_size)
		if (ps->a_stack[i] < ps->a_stack[i - 1])
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

void	radix_sort(t_struct *ps)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (!is_sort(ps))
	{
		while (i < ps->nb_size)
		{
			if (!get_index(ps->a_stack[0], index))
				pb(ps);
			else
				ra(ps);
			i++;
		}
		i = 0;
		while (ps->b_size > 0)
			pa(ps);
		index++;
	}
}
