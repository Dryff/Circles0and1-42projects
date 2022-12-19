/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:16:09 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/17 15:43:53 by colas            ###   ########.fr       */
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
	i = 0;
	printf("\n");
	while (i < data->nb_size)
	{
		printf("nb_sort[%d] = %d\n", i, data->nb_sort[i]);
		i++;
	}
}