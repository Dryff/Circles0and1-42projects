/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:30:49 by colas             #+#    #+#             */
/*   Updated: 2023/01/03 15:44:54 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	get_map(char *file_name)
{
	int		fd;
	int		i;
	int		j;
	t_map	map;

	fd = open(file_name, O_RDONLY);
	if (!fd)
		exit(1);
	i = 0;
	while (get_next_line(fd) != 0)
		i++;
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (!fd)
		exit(1);
	map.line = malloc(sizeof(t_array) * i);
	if (!map.line)
		exit(1);
	j = 0;
	while (j < i)
	{
		map.line[j] = ft_split_to_int(get_next_line(fd), ' ');
		j++;
	}
	return (map.row_nbr = i, map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_err_printf("USAGE : ./fdf {MAP_FILE}"), 1);
	map = get_map(argv[1]);
	ft_err_printf("row : %d, line : %d\n", map.row_nbr, map.line->size);
	int j;
	int k;
	k = 0;
	j = 0;
	while (j < 9)
	{
		k = 0;
		while (k < map.line->size)
		{
			ft_err_printf("%d", map.line[j].arr[k]);
			ft_err_printf(":%s ", map.line[j].color[k++]);
		}
		ft_err_printf("\n");
		j++;
	}
	mlx_draw(map);
}
