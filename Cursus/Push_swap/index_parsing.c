/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:07:31 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/19 17:06:42 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	general_sort(t_struct *ps)
{
	if (ps->a_size < 2)
		return (0);
	else if (ps->a_size == 3)
		return (sort_three(ps), 0);
	else if (ps->a_size == 5)
		return (sort_five(ps), 0);
	else
	{
		binary_index_parse(ps);
		radix_sort(ps);
	}
	return (0);
}

static	long	dec_to_bin(long n)
{
	long	bin;
	long	dec;
	long	i;

	bin = 0;
	dec = n;
	i = 1;
	while (dec > 0)
	{
		bin += (dec % 2) * i;
		dec /= 2;
		i *= 10;
	}
	return (bin);
}

static	int	get_index_sorted(t_struct *ps, int nb)
{
	int	i;

	i = 0;
	while (i < ps->nb_size)
	{
		if (nb == ps->nb_sort[i])
			return (i);
		i++;
	}
	return (0);
}

void	binary_index_parse(t_struct *ps)
{
	int	i;

	i = 0;
	while (i < ps->a_size)
	{
		ps->a_stack[i] = dec_to_bin(get_index_sorted(ps, ps->a_stack[i]));
		i++;
	}
}
