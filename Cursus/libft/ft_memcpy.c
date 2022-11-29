/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:09:34 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 12:13:46 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*tab1;
	const char	*tab2;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	tab1 = dst;
	tab2 = src;
	while (i < len)
	{
		tab1[i] = tab2[i];
		i++;
	}
	return (dst);
}
