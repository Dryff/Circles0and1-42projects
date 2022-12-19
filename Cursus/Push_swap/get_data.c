/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:08:15 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/19 17:08:15 by cgelin           ###   ########.fr       */
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
	t_struct	ps;

	i = 0;
	j = 0;
	size = get_size(str);
	ps.a_stack = ft_calloc(sizeof(int), size + 1);
	if (!ps.a_stack)
		return (free(ps.a_stack), ps);
	ps.b_stack = ft_calloc(sizeof(int), size + 1);
	if (!ps.b_stack)
		return (free(ps.b_stack), free(ps.a_stack), ps);
	ps.nb_sort = ft_calloc(sizeof(int), size + 1);
	if (!ps.a_stack)
		return (free(ps.b_stack), free(ps.a_stack), free(ps.nb_sort), ps);
	while (j < size)
	{
		ps.a_stack[j] = ft_atoi(&str[i]);
		i = get_next_i(str, i);
		j++;
	}
	return (ps.nb_size = size, ps.a_size = size, ps.b_size = 0, ps);
}

t_struct	get_args(int argc, char **str)
{
	int			i;
	t_struct	ps;

	i = 1;
	ps.a_stack = ft_calloc(sizeof(int), argc);
	if (!ps.a_stack)
		return (free(ps.a_stack), ps);
	ps.b_stack = ft_calloc(sizeof(int), argc);
	if (!ps.b_stack)
		return (free(ps.b_stack), free(ps.a_stack), ps);
	ps.nb_sort = ft_calloc(sizeof(int), argc);
	if (!ps.a_stack)
		return (free(ps.b_stack), free(ps.a_stack), free(ps.nb_sort), ps);
	ps.a_size = argc - 1;
	ps.nb_size = argc - 1;
	ps.b_size = 0;
	while (i < argc)
	{
		ps.a_stack[i - 1] = ft_atoi(str[i]);
		i++;
	}
	return (ps);
}
