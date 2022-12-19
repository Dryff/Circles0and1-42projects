/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:51:05 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 12:11:32 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	sa(t_struct *data)
{
	int	tmp;

	if (data->a_size > 1)
	{
		tmp = data->a_stack[1];
		data->a_stack[1] = data->a_stack[0];
		data->a_stack[0] = tmp;
	}
	ft_putendl("sa");
}

void	sb(t_struct *data)
{
	int	tmp;

	if (data->b_size > 1)
	{
		tmp = data->b_stack[1];
		data->b_stack[1] = data->b_stack[0];
		data->b_stack[0] = tmp;
	}
	ft_putendl("sb");
}

void	ss(t_struct *data)
{
	int	tmp;

	if (data->b_size > 1)
	{
		tmp = data->b_stack[1];
		data->b_stack[1] = data->b_stack[0];
		data->b_stack[0] = tmp;
	}
	if (data->a_size > 1)
	{
		tmp = data->a_stack[1];
		data->a_stack[1] = data->a_stack[0];
		data->a_stack[0] = tmp;
	}
	ft_putendl("ss");
}
