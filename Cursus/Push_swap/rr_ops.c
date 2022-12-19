/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_rotate_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:36:32 by colas          #+#    #+#             */
/*   Updated: 2022/12/17 14:30:36 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	ra(t_struct *ps)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = ps->a_stack[0];
	while (i < ps->a_size - 1)
	{
		ps->a_stack[i] = ps->a_stack[i + 1];
		i++;
	}
	ps->a_stack[i] = tmp;
	ft_putendl_fd("ra", 1);
}

void	rb(t_struct *ps)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = ps->b_stack[0];
	while (i < ps->b_size - 1)
	{
		ps->b_stack[i] = ps->b_stack[i + 1];
		i++;
	}
	ps->b_stack[i] = tmp;
	ft_putendl_fd("rb", 1);
}

void	rr(t_struct *ps)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = ps->b_stack[0];
	while (i < ps->b_size - 1)
	{
		ps->b_stack[i] = ps->b_stack[i + 1];
		i++;
	}
	ps->b_stack[i] = tmp;
	i = 0;
	tmp = ps->a_stack[0];
	while (i < ps->a_size - 1)
	{
		ps->a_stack[i] = ps->a_stack[i + 1];
		i++;
	}
	ps->a_stack[i] = tmp;
	ft_putendl_fd("rr", 1);
}
