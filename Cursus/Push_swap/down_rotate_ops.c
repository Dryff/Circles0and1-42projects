/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_rotate_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 07:36:32 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/06 12:56:48 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	ra(t_struct data)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data.a_stack[0];
	while (i < data.a_size - 1)
	{
		data.a_stack[i] = data.a_stack[i + 1];
		i++;
	}
	data.a_stack[i] = tmp;
	ft_putendl("ra");
}

void	rb(t_struct data)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data.b_stack[0];
	while (i < data.b_size - 1)
	{
		data.b_stack[i] = data.b_stack[i + 1];
		i++;
	}
	data.b_stack[i] = tmp;
	ft_putendl("rb");
}

void	rr(t_struct data)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = data.b_stack[0];
	while (i < data.b_size - 1)
	{
		data.b_stack[i] = data.b_stack[i + 1];
		i++;
	}
	data.b_stack[i] = tmp;
	i = 0;
	tmp = data.a_stack[0];
	while (i < data.a_size - 1)
	{
		data.a_stack[i] = data.a_stack[i + 1];
		i++;
	}
	data.a_stack[i] = tmp;
	ft_putendl("rr");
}
