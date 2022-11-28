/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:03:34 by colas             #+#    #+#             */
/*   Updated: 2022/11/28 14:26:40 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
    if (len + start > ft_strlen((char *)s))
        len = ft_strlen((char *)s) - start;
	str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
	if (start >= ft_strlen((char *)s))
		return (str);
	if (str == NULL)
		return (NULL);
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_count_word(char const *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

void    free_all(char **strs)
{
    int i;

    i = 0;
	while (strs[i])
    {
		free(strs[i]);
        i++;
    }
	free(strs);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_count_word(s, c);
	if (!(strs = (char **)malloc((word + 1) * sizeof(char *))))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
        if (!strs[j])
			return (free_all(strs), NULL);
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
