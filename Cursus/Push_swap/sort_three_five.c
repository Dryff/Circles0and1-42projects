/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:03:01 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/19 17:07:30 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

static	int	is_in_b(t_struct *ps, int tmp)
{
	int	i;

	i = 0;
	while (i < ps->b_size)
	{
		if (ps->b_stack[i] == tmp)
			return (1);
		i++;
	}
	return (0);
}

static	int	get_number_above(t_struct *ps, int tmp)
{
	int	i;

	i = 0;
	if ((ps->nb_sort[ps->nb_size - 1]) == tmp)
		return (ps->nb_sort[0]);
	while (ps->nb_sort[i] != tmp)
		i++;
	return (ps->nb_sort[i + 1]);
}

int	sort_three(t_struct *ps)
{
	int	a1;
	int	a2;
	int	a3;

	a1 = ps->a_stack[0];
	a2 = ps->a_stack[1];
	a3 = ps->a_stack[2];
	if (a1 < a2 && a2 > a3 && a3 > a1)
		return (rra(ps), sa(ps), 1);
	if (a1 > a2 && a2 > a3)
		return (ra(ps), sa(ps), 1);
	if (a1 > a2 && a2 < a3 && a1 > a3)
		return (ra(ps), 1);
	if (a1 > a2 && a2 < a3 && a3 > a1)
		return (sa(ps), 1);
	if (a1 < a2 && a2 > a3 && a3 < a1)
		return (rra(ps), 1);
	return (1);
}

int	push_number_to_top(t_struct *ps, int nb)
{
	int	i;
	int	top_dist;
	int	bot_dist;

	i = 0;
	while (ps->a_stack[i] != nb)
		i++;
	bot_dist = i;
	top_dist = ps->a_size - i;
	i = 0;
	while (ps->a_stack[0] != nb)
	{
		if (top_dist > bot_dist)
			ra(ps);
		else
			rra(ps);
		i++;
	}
	return (10040);
}

int	sort_five(t_struct *ps)
{
	int	tmp;

	pb(ps);
	pb(ps);
	sort_three(ps);
	tmp = ps->b_stack[0];
	if (is_in_b(ps, get_number_above(ps, tmp)))
		sb(ps);
	tmp = ps->b_stack[0];
	push_number_to_top(ps, get_number_above(ps, tmp));
	pa(ps);
	tmp = ps->b_stack[0];
	push_number_to_top(ps, get_number_above(ps, tmp));
	pa(ps);
	push_number_to_top(ps, ps->nb_sort[0]);
	return (0);
}
