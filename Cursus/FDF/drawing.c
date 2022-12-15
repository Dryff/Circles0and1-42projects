/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:33 by colas             #+#    #+#             */
/*   Updated: 2022/12/15 09:24:46 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void render_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.5);
	*y = (*x + *y) * sin(0.5) - z;
}

void	bresenham(t_pos pos, float x1, float y1, t_data fdf)
{
	float	x_step;
	float	y_step;
	int		max;

	pos.z = fdf.map.line[(int)pos.y].arr[(int)pos.x];
	pos.z1 = fdf.map.line[(int)y1].arr[(int)x1];
	pos.color = get_color(pos);
	x_step = x1 - pos.x;
	y_step = y1 - pos.y;
	pos.xy_scale = 15;
	pos.x *= pos.xy_scale;
	x1 *= pos.xy_scale;
	pos.y *= pos.xy_scale;
	y1 *= pos.xy_scale;
	printf("res : %f", (pos.x - pos.y) * cos(0.5));
	// render_isometric(&pos.x, &pos.y, pos.z);
	// render_isometric(&x1, &y1, pos.z1);
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(pos.x - x1) || (int)(pos.y - y1))
	{
		my_mlx_pixel_put(&fdf, (int)pos.x + 500, (int)pos.y + 300, pos.color);
		pos.x += x_step;
		pos.y += y_step;
	}
}

void	draw_lines(t_data fdf)
{
	t_pos	pos;
	int x;
	int y;

	y = 0;
	pos.y = 0;
	while (y < fdf.map.row_nbr)
	{
		x = 0;
		pos.x = 0;
		while (x < fdf.map.line[y].size)
		{		
				if (x < fdf.map.line[y].size - 1)
					bresenham(pos, x + 1, y, fdf);
				if (y < fdf.map.row_nbr - 1)
					bresenham(pos, x, y + 1, fdf);
				x++;
				pos.x = x;
		}
		y++;
		printf("\n");
		pos.y = y;
	}
}

void	mlx_draw(t_map map)
{
	t_data	fdf;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 675, "SynthWave");
	fdf.img = mlx_new_image(mlx, 1200, 675);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pixel, \
	&fdf.line_length, &fdf.endian);
	fdf.map = map;
	draw_lines(fdf);
	mlx_put_image_to_window(mlx, mlx_win, fdf.img, 0, 0);
	mlx_loop(mlx);
}
