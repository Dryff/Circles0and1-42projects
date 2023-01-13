/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:30:49 by colas             #+#    #+#             */
/*   Updated: 2023/01/13 15:32:56 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_max_min(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	map->i_max = 0;
	map->i_min = 0;
	while (i < map->row_nbr)
	{
		j = 0;
		while (j < map->line->size)
		{
			if (map->line[i].arr[j] > map->i_max)
				map->i_max = map->line[i].arr[j];
			if (map->line[i].arr[j] < map->i_min)
				map->i_min = map->line[i].arr[j];
			j++;
		}
		i++;
	}
	printf("%d\n", map->i_max);
	printf("%d\n", map->i_min);
}

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
	return (map.row_nbr = i, get_max_min(&map), map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_err_printf("USAGE : ./fdf {MAP_FILE}"), 1);
	map = get_map(argv[1]);
	ft_err_printf("row : %d, line : %d\n", map.row_nbr, map.line->size);
	mlx_draw(map);
	free(map.line);
}
