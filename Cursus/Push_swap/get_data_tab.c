/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:12:44 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/15 19:45:44 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

t_struct	get_data_tab(int argc, char **str)
{
	int			i;
	t_struct	data;

	i = 0;
	data.a_stack = ft_calloc(sizeof(int), (argc));
	data.b_stack = ft_calloc(sizeof(int), (argc));
	data.nbrs = ft_calloc(sizeof(int), (argc));
	if (!data.a_stack || !data.b_stack || !data.nbrs)
		return (data);
	data.a_size = argc - 1;
	data.nbrs_size = argc - 1;
	data.b_size = 0;
	while (i < argc - 1)
	{
		data.a_stack[i] = ft_atoi(str[i]);
		i++;
	}
	sort_tab(&data);
	return (data);
}
