/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:26:59 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 17:06:47 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	pa(t_struct *ps)
{
	int	i;

	i = ps->a_size;
	if (ps->b_size == 0)
		return ;
	while (i >= 0)
	{
		ps->a_stack[i] = ps->a_stack[i - 1];
		i--;
	}
	ps->a_stack[0] = ps->b_stack[0];
	i = 0;
	while (i < ps->b_size - 1)
	{
		ps->b_stack[i] = ps->b_stack[i + 1];
		i++;
	}
	ps->b_stack[ps->b_size - 1] = 0;
	ps->a_size++;
	ps->b_size--;
	ft_putendl_fd("pa", 1);
}

void	pb(t_struct *ps)
{
	int	i;

	i = ps->b_size;
	if (ps->a_size == 0)
		return ;
	while (i >= 0)
	{
		ps->b_stack[i] = ps->b_stack[i - 1];
		i--;
	}	
	ps->b_stack[0] = ps->a_stack[0];
	i = 0;
	while (i < ps->a_size - 1)
	{
		ps->a_stack[i] = ps->a_stack[i + 1];
		i++;
	}
	ps->a_stack[ps->a_size - 1] = 0;
	ps->b_size++;
	ps->a_size--;
	ft_putendl_fd("pb", 1);
}
