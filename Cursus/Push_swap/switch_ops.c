/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:51:05 by mfinette          #+#    #+#             */
/*   Updated: 2022/12/06 12:56:58 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	sa(t_struct data)
{
	int	tmp;

	if (data.a_size > 1)
	{
		tmp = data.a_stack[1];
		data.a_stack[1] = data.a_stack[0];
		data.a_stack[0] = tmp;
	}
	ft_putendl("sa");
}

void	sb(t_struct data)
{
	int	tmp;

	if (data.b_size > 1)
	{
		tmp = data.b_stack[1];
		data.b_stack[1] = data.b_stack[0];
		data.b_stack[0] = tmp;
	}
	ft_putendl("sb");
}

void	ss(t_struct data)
{
	int	tmp;

	if (data.b_size > 1)
	{
		tmp = data.b_stack[1];
		data.b_stack[1] = data.b_stack[0];
		data.b_stack[0] = tmp;
	}
	if (data.a_size > 1)
	{
		tmp = data.a_stack[1];
		data.a_stack[1] = data.a_stack[0];
		data.a_stack[0] = tmp;
	}
	ft_putendl("ss");
}
