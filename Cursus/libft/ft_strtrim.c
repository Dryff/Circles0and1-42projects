/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:10 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 12:14:56 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
	i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*t;
	int		k;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (check_char(s1[i], set))
		i++;
	k = ft_strlen((char *)s1) - 1;
	while (check_char(s1[k], set) && s1[i])
		k--;
	t = malloc(sizeof(char) * (k - i + 2));
	if (!t)
		return (NULL);
	while (i <= k)
	{
		t[j] = s1[i];
		i++;
		j++;
	}
	t[j] = 0;
	return (t);
}
