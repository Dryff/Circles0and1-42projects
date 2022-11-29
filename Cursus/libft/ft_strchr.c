/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:19 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 12:14:06 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*d;
	unsigned char	u;
	int				i;

	i = 0;
	u = (unsigned char)c;
	d = (char *)s;
	while (d[i])
	{
		if (u == d[i])
			return (&d[i]);
		i++;
	}
	if (d[i] == u)
		return (&d[i]);
	return (NULL);
}
