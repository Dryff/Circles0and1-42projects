/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:16:09 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/15 19:59:49 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	print_tabs(t_struct *data)
{
	int	i;

	i = 0;
	printf("\n");
	while (i < data->a_size)
	{
		printf("a[%d] = %d\n", i, data->a_stack[i]);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < data->b_size)
	{
		printf("b[%d] = %d\n", i, data->b_stack[i]);
		i++;
	}
}