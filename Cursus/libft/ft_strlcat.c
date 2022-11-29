/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:34:02 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/15 18:36:32 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char		*destination;
	const char	*source;
	int			size;
	int			len_dest;

	destination = dest;
	source = src;
	size = dstsize;
	while (size-- != 0 && *destination != '\0')
		destination++;
	len_dest = destination - dest;
	size = dstsize - len_dest;
	if (size == 0)
		return (len_dest + ft_strlen(source));
	while (*source != '\0')
	{
		if (size != 1)
		{
			*destination++ = *source;
			size--;
		}
		source++;
	}
	*destination = '\0';
	return (len_dest + (source - src));
}
