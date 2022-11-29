/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:19 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 12:14:52 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*d;
	unsigned char	u;
	int				i;

	i = ft_strlen(s);
	d = (unsigned char *)s;
	u = (unsigned char)c;
	while (i > 0)
	{
		if (u == d[i])
			return ((char *)&d[i]);
		i--;
	}
	if (d[ft_strlen(s)] == u)
		return ((char *)&d[ft_strlen(s)]);
	if (d[i] == u)
		return ((char *)&d[i]);
	return (NULL);
}
