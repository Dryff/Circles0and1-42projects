/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:26:59 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 12:11:25 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	pa(t_struct *data)
{
	int	i;

	i = data->a_size;
	if (data->b_size == 0)
		return ;
	while (i >= 0)
	{
		data->a_stack[i] = data->a_stack[i - 1];
		i--;
	}
	data->a_stack[0] = data->b_stack[0];
	i = 0;
	while (i < data->b_size - 1)
	{
		data->b_stack[i] = data->b_stack[i + 1];
		i++;
	}
	data->b_stack[data->b_size - 1] = 0;
	data->a_size++;
	data->b_size--;
	ft_putendl("pa");
}

void	pb(t_struct *data)
{
	int	i;

	i = data->b_size;
	if (data->a_size == 0)
		return ;
	while (i >= 0)
	{
		data->b_stack[i] = data->b_stack[i - 1];
		i--;
	}	
	data->b_stack[0] = data->a_stack[0];
	i = 0;
	while (i < data->a_size - 1)
	{
		data->a_stack[i] = data->a_stack[i + 1];
		i++;
	}
	data->a_stack[data->a_size - 1] = 0;
	data->b_size++;
	data->a_size--;
	ft_putendl("pb");
}
