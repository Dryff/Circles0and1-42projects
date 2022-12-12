/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:33 by colas             #+#    #+#             */
/*   Updated: 2022/12/12 21:01:30 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_map(t_map map, t_data img)
{
	int y;
	int x;
	int scale;

	y = 0;
	scale = 10;
	while (y < map.row_nbr)
	{
		x = 0;
		while (x < map.line[y].size)
		{
			if (map.line[y].arr[x] == 0)
				my_mlx_pixel_put(&img, x * scale + 500, y * scale + 300, 0x0000FF00);
			else if (map.line[y].arr[x] != 0)
				my_mlx_pixel_put(&img, x * scale + 500, y * scale + 300, 0x00FF0000);
			x++;
		}
		y++;
	}
}

void	mlx_draw(t_map map)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 675, "SynthWave");
	img.img = mlx_new_image(mlx, 1200, 675);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,\
	&img.endian);
	draw_map(map, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}