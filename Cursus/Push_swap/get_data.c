/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:08:15 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/17 15:59:49 by colas            ###   ########.fr       */
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
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

t_struct	get_str(char *str)
{
	size_t		i;
	size_t		j;
	size_t		size;
	t_struct	data;

	(void) size;
	(void) str;
	i = 0;
	j = 0;
	size = get_size(str);
	data.a_stack = ft_calloc(sizeof(int), size + 1);
	data.b_stack = ft_calloc(sizeof(int), size + 1);
	data.nb_sort = ft_calloc(sizeof(int), size + 1);
	if (!data.a_stack || !data.b_stack || !data.nb_sort)
		return (data);
	while (j < size)
	{
		data.a_stack[j] = ft_atoi(&str[i]);
		i = get_next_i(str, i);
		j++;
	}
	data.nb_size = size;
	data.a_size = size;
	data.b_size = 0;
	return (data);
}

t_struct	get_args(int argc, char **str)
{
	int			i;
	t_struct	data;

	i = 1;
	data.a_stack = ft_calloc(sizeof(int), (argc));
	data.b_stack = ft_calloc(sizeof(int), (argc));
	data.nb_sort = ft_calloc(sizeof(int), (argc));
	if (!data.a_stack || !data.b_stack || !data.nb_sort)
		return (data);
	data.a_size = argc - 1;
	data.nb_size = argc - 1;
	data.b_size = 0;
	while (i < argc)
	{
		data.a_stack[i - 1] = ft_atoi(str[i]);
		i++;
	}
	return (data);
}