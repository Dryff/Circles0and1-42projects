/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:08:19 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/14 14:32:11 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*itoa_min(void)
{
	char	*s;
	char	*imax;
	int		i;

	i = 0;
	imax = "-2147483648";
	s = malloc(sizeof(char) * 12);
	if (!s)
		return (NULL);
	while (imax[i])
	{
		s[i] = imax[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*s;

	if (n == -2147483648)
		return (itoa_min());
	l = len(n);
	s = malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	l--;
	while (n > 0)
	{
		s[l] = n % 10 + 48;
		n /= 10;
		l--;
	}
	return (s);
}
