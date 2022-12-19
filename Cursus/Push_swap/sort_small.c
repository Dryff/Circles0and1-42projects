/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:03:01 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/18 11:49:10 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

static	int	is_in_b(t_struct *data, int tmp)
{
	int	i;

	i = 0;
	while (i < data->b_size)
	{
		if (data->b_stack[i] == tmp)
			return (1);
		i++;
	}
	return (0);
}

static	int	get_number_above(t_struct *data, int tmp)
{
	int	i;

	i = 0;
	if ((data->nb_sort[data->nb_size - 1]) == tmp)
		return (data->nb_sort[0]);
	while (data->nb_sort[i] != tmp)
		i++;
	return (data->nb_sort[i + 1]);
}

int	sort_three(t_struct *data)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = data->a_stack[0];
	a2 = data->a_stack[1];
	a3 = data->a_stack[2];
	if (a1 < a2 && a2 > a3 && a3 > a1)
		return (rra(data), sa(data), 1);
	if (a1 > a2 && a2 > a3)
		return (ra(data), sa(data), 1);
	if (a1 > a2 && a2 < a3 && a1 > a3)
		return (ra(data), 1);
	if (a1 > a2 && a2 < a3 && a3 > a1)
		return (sa(data), 1);
	if (a1 < a2 && a2 > a3 && a3 < a1)
		return (rra(data), 1);
	return (1);
}


int	push_number_to_top(t_struct *data, int nb)
{
	int	i;
	int	top_dist;
	int	bot_dist;

	i = 0;
	while (data->a_stack[i] != nb)
		i++;
	bot_dist = i;
	top_dist = data->a_size - i;
	i = 0;
	while (data->a_stack[0] != nb)
	{
		if (top_dist > bot_dist)
			ra(data);
		else
			rra(data);
		i++;
	}
	return (10040);
}

int	sort_five(t_struct *data)
{
	int	tmp;

	pb(data);
	pb(data);
	sort_three(data);
	tmp = data->b_stack[0];
	if (is_in_b(data, get_number_above(data, tmp)))
		sb(data);
	tmp = data->b_stack[0];
	push_number_to_top(data, get_number_above(data, tmp));
	pa(data);
	tmp = data->b_stack[0];
	push_number_to_top(data, get_number_above(data, tmp));
	pa(data);
	push_number_to_top(data, data->nb_sort[0]);
	return (0);
}