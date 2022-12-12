/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:30:49 by colas             #+#    #+#             */
/*   Updated: 2022/12/12 18:03:58 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	*get_line(fd)
// {
// 	char *line;
// 	int *tab;
// 	int i;
// 	int j;

// 	line = get_next_line(fd);
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (line[i] != '\n')
// 	{
// 		while (line[i] == ' ')
// 			i++;
// 		if (line[i] >= '0' && line[i] <= '9'))
// 			tab[j++] == get_number(line, i);
// 		while (line[i] >= '0' && line[i] <= '9'))
// 			i++;
// 	}
// 	return (tab);
// }

t_map get_map(char *file_name)
{
	int fd;
	int i;
	int j;
	t_map map;

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
	map.line = malloc(sizeof(map.line) * i);
	if (!map.line)
		exit(1);
	j = 0;
	while (j < i)
	{
		map.line[j] = ft_split_to_int(get_next_line(fd), ' ');
		j++;
	}
	map.row_nbr = i;
	return (map);
}

int main(int argc, char **argv)
{
	t_map map;
	
	if (argc != 2)
		return (ft_err_printf("USAGE : ./fdf {MAP_FILE}"), 1);
	map = get_map(argv[1]);
	int j;
	int k;
	k = 0;
	j = 0;
	while (j < 11)
	{
		k = 0;
		while (k < map.line->size)
			ft_err_printf("%d", map.line[j].arr[k++]);
		ft_err_printf("\n");
		j++;
	}
	mlx_draw(map);
}
