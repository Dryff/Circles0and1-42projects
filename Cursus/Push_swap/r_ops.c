/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:03:15 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 17:06:56 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	rra(t_struct *ps)
{
	int	tmp;
	int	i;

	i = ps->a_size - 1;
	tmp = ps->a_stack[ps->a_size - 1];
	while (i > 0)
	{
		ps->a_stack[i] = ps->a_stack[i - 1];
		i--;
	}
	ps->a_stack[i] = tmp;
	ft_putendl_fd("rra", 1);
}

void	rrb(t_struct *ps)
{
	int	tmp;
	int	i;

	i = ps->b_size - 1;
	tmp = ps->b_stack[ps->b_size - 1];
	while (i > 0)
	{
		ps->b_stack[i] = ps->b_stack[i - 1];
		i--;
	}
	ps->b_stack[i] = tmp;
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_struct *ps)
{
	int	tmp;
	int	i;

	i = ps->a_size - 1;
	tmp = ps->a_stack[ps->a_size - 1];
	while (i > 0)
	{
		ps->a_stack[i] = ps->a_stack[i - 1];
		i--;
	}
	ps->a_stack[i] = tmp;
	i = ps->b_size - 1;
	tmp = ps->b_stack[ps->b_size - 1];
	while (i > 0)
	{
		ps->b_stack[i] = ps->b_stack[i - 1];
		i--;
	}
	ps->b_stack[i] = tmp;
	ft_putendl_fd("rrr", 1);
}
