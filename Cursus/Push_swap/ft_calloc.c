/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:22:54 by cgelin            #+#    #+#             */
/*   Updated: 2022/12/15 19:23:11 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "header_ps.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (0);
	space = (void *)malloc(size * nmemb);
	if (!space)
		return (0);
	ft_bzero(space, size * nmemb);
	return (space);
}
