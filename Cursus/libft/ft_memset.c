/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:09:27 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 12:13:54 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = b;
	while (i < n)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
