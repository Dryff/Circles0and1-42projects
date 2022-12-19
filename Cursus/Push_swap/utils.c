/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:37:26 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 12:09:52 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	ft_atoi(const char *str)
{
	int				i;
	long long int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r' )
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{	
		if (nb != ((nb * 10 + (sign * (str[i] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		nb = nb * 10 + (str[i] - '0') * sign;
		i++;
	}
	return ((int)nb);
}

void	assign_index(t_struct *ps)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	j = 0;
	while (++i < ps->a_size)
		ps->nb_sort[i] = ps->a_stack[i];
	i = 0;
	while (i < ps->a_size)
	{
		j = i + 1;
		while (j < ps->a_size)
		{
			if (ps->nb_sort[j] < ps->nb_sort[i])
			{
				temp = ps->nb_sort[i];
				ps->nb_sort[i] = ps->nb_sort[j];
				ps->nb_sort[j] = temp;
			}
			j++;
		}
		i++;
	}
}

 static	void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t bits, size_t size)
{
	void	*space;

	if (bits && size > SIZE_MAX / bits)
		return (0);
	space = (void *)malloc(size * bits);
	if (!space)
		return (0);
	ft_bzero(space, size * bits);
	return (space);
}
