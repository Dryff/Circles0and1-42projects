/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:04:46 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 18:06:28 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ')
		return (1);
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
	}
	write(fd, "\n", 1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == '0')
		i++;
	while (s[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n)
	{
		if ((s1[i] == '\0' && s2[i] == '\0') || i == n - 1)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}
