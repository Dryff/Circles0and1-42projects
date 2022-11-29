/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:18:49 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 12:32:57 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;
	char	*str;
	size_t	j;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = (size_t)start;
	j = 0;
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	if (start > ft_strlen(str))
		len = 0;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (str[i] && j < len)
	{
		tab[j] = str[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
