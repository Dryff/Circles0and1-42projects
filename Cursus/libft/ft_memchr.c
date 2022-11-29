/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:04:50 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 12:23:31 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	d;
	size_t			i;

	d = (unsigned char)c;
	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == d)
			return (&src[i]);
		i++;
	}
	return (0);
}
