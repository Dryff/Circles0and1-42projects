/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:03:15 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/06 12:57:01 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	rra(t_struct data)
{
	int	tmp;
	int	i;

	i = data.a_size - 1;
	tmp = data.a_stack[data.a_size - 1];
	while (i > 0)
	{
		data.a_stack[i] = data.a_stack[i - 1];
		i--;
	}
	data.a_stack[i] = tmp;
	ft_putendl("rra");
}

void	rrb(t_struct data)
{
	int	tmp;
	int	i;

	i = data.b_size - 1;
	tmp = data.b_stack[data.b_size - 1];
	while (i > 0)
	{
		data.b_stack[i] = data.b_stack[i - 1];
		i--;
	}
	data.b_stack[i] = tmp;
	ft_putendl("rrb");
}

void	rrr(t_struct data)
{
	int	tmp;
	int	i;

	i = data.a_size - 1;
	tmp = data.a_stack[data.a_size - 1];
	while (i > 0)
	{
		data.a_stack[i] = data.a_stack[i - 1];
		i--;
	}
	data.a_stack[i] = tmp;
	i = data.b_size - 1;
	tmp = data.b_stack[data.b_size - 1];
	while (i > 0)
	{
		data.b_stack[i] = data.b_stack[i - 1];
		i--;
	}
	data.b_stack[i] = tmp;
	ft_putendl("rrr");
}
