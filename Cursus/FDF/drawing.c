/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:33 by colas             #+#    #+#             */
/*   Updated: 2022/12/13 17:27:48 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(t_map map, t_data img)
{
	int		y;
	int		x;
	int		scale;

	y = 0;
	scale = 15;
	while (y < map.row_nbr)
	{
		x = 0;
		while (x < map.line[y].size)
		{
			if (map.line[y].arr[x] == 0)
				my_mlx_pixel_put(&img, x * scale + 500, \
				y * scale + 300, 0x0000FF00);
			else if (map.line[y].arr[x] != 0)
				my_mlx_pixel_put(&img, x * scale + 500, \
				y * scale + 300, 0x00FF0000);
			x++;
		}
		y++;
	}
}

void	bresenham(t_pos pos, float x1, float y1, t_data img)
{
	float	x_step;
	float	y_step;
	int		max;

	pos.scale = 15;
	pos.x *= pos.scale;
	x1 *= pos.scale;
	pos.y *= pos.scale;
	y1 *= pos.scale;

	x_step = x1 - pos.x;
	y_step = y1 - pos.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(pos.x - x1) || (int)(pos.y - y1))
	{
		my_mlx_pixel_put(&img, (int)pos.x + 500, (int)pos.y + 300, pos.color);
		pos.x += x_step;
		pos.y += y_step;
	}
}

void	draw_lines(t_map map, t_data img)
{
	t_pos	pos;
	(void) img;

	pos.y = 0;
	while (pos.y < map.row_nbr)
	{
		pos.x = 0;
		while (pos.x < map.line[pos.y].size)
		{	
			if (map.line[pos.y].arr[pos.x] == 10)
				pos.color = 0x00FF0000;
			else
				pos.color = 0x000000FF;
				if (pos.x < map.line[pos.y].size - 1)
					bresenham(pos, pos.x + 1, pos.y, img);
				if (pos.y < map.row_nbr - 1)
					bresenham(pos, pos.x, pos.y + 1, img);
				pos.x++;
		}
		pos.y++;
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
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	draw_map(map, img);
	draw_lines(map, img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
