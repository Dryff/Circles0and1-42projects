/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:08:15 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/15 19:45:59 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

static	int	get_next_i(char *str, int i)
{
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

static	size_t	get_size(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count + 1);
}

t_struct	get_data_str(char *str)
{
	size_t		i;
	size_t		j;
	size_t		size;
	t_struct	data;

	i = 0;
	j = 0;
	size = get_size(str);
	data.a_stack = ft_calloc(sizeof(int), size);
	data.b_stack = ft_calloc(sizeof(int), size);
	data.nbrs = ft_calloc(sizeof(int), size);
	if (!data.a_stack || !data.b_stack || !data.nbrs)
		return (data);
	while (j < size)
	{
		data.a_stack[j] = ft_atoi(&str[i]);
		i = get_next_i(str, i);
		j++;
	}
	data.nbrs_size = size;
	data.a_size = size;
	data.b_size = 0;
	sort_tab(&data);
	return (data);
}