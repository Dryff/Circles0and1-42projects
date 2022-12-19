/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:51:05 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 17:07:27 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	sa(t_struct *ps)
{
	int	tmp;

	if (ps->a_size > 1)
	{
		tmp = ps->a_stack[1];
		ps->a_stack[1] = ps->a_stack[0];
		ps->a_stack[0] = tmp;
	}
	ft_putendl_fd("sa", 1);
}

void	sb(t_struct *ps)
{
	int	tmp;

	if (ps->b_size > 1)
	{
		tmp = ps->b_stack[1];
		ps->b_stack[1] = ps->b_stack[0];
		ps->b_stack[0] = tmp;
	}
	ft_putendl_fd("sb", 1);
}

void	ss(t_struct *ps)
{
	int	tmp;

	if (ps->b_size > 1)
	{
		tmp = ps->b_stack[1];
		ps->b_stack[1] = ps->b_stack[0];
		ps->b_stack[0] = tmp;
	}
	if (ps->a_size > 1)
	{
		tmp = ps->a_stack[1];
		ps->a_stack[1] = ps->a_stack[0];
		ps->a_stack[0] = tmp;
	}
	ft_putendl_fd("ss", 1);
}
