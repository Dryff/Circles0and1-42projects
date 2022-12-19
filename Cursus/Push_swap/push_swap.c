/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:30:38 by colas             #+#    #+#             */
/*   Updated: 2022/12/19 12:34:01 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h" 

int	check_int(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 11)
		return (0);
	if (len == 11)
		if (ft_strncmp("-2147483648", str, 11) < 0)
			return (0);
	if (len == 10)
		if (ft_strncmp("2147483647", str, 10) < 0)
			return (0);
	return (1);
}

int	check_int_one_str(char *str, char *max_min, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			count++;
		else
			count = 0;
		if (count == len)
		{
			if (ft_strncmp(max_min, &str[i - (len - 1)], len) < 0)
				return (0);
			break ;
		}
		i++;
	}
	return (1);
}

int	check_signs(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		if ((str[i] >= '0' && str[i] <= '9') && str[i + 1] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	check_str(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		exit(1);
	i = 1;
	if (argc == 2)
		if (!check_int_one_str(argv[i], "-2147483648", 11) || \
			!check_int_one_str(argv[i], "2147483647", 10))
			return (0);
	if (argc != 2)
		while (argv[i])
			if (!check_int(argv[i++]))
				return (0);
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (0);
		if (!check_signs(argv[i]))
			return (0);
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	t_struct	ps;

	if (!check_str(argc, argv))
		return (ft_putendl("USAGE: ./push_swap int1 int2 int3.. intn"), 1);
	if (argc == 2)
		ps = get_str(argv[1]);
	else
		ps = get_args(argc, argv);
	assign_index(&ps);
	print_tabs(&ps);
	general_sort(&ps);
	print_tabs(&ps);
	return (0);
}
