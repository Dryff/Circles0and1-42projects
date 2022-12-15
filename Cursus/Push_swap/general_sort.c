/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:01:23 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/15 21:07:27 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	general_sort(t_struct *data)
{
	if (data->a_size < 2)
		return (0);
	else if (data->a_size == 3)
		return (sort_three(data), 0);
	else if (data->a_size == 5)
		return (sort_five(data), 0);
	else
	{
		binary_index_parse(data);
		radix_sort(data);	
	}
	return (0);
}