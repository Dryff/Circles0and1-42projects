/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:12:33 by colas             #+#    #+#             */
/*   Updated: 2023/01/13 15:57:13 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	check_inbound(t_pos p, t_data fdf)
{
	if ((p.x + fdf.offsetx <= 1 || p.y + fdf.offsety >= 674 \
	|| p.x + fdf.offsetx >= 1199 || p.y + fdf.offsety <= 1))
		return (0);
	return (1);
}

int	get_keys(int key, t_data *fdf)
{
	if (key == 53)
		ft_close(fdf);
	move(fdf, key);
	zoom(fdf, key);
	iso(key, fdf);
	rotate(key, fdf);
	colors(key, fdf);
	printf("%d\n", key);
	fdf->img = mlx_new_image(fdf->mlx, 1200, 675);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
	&fdf->line_length, &fdf->endian);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
	return (0);
}

void	bresenham(t_pos pos, float x1, float y1, t_data fdf)
{
	float	x_step;
	float	y_step;
	int		color;

	assign_pos(&pos, fdf, &x1, &y1);
	color = get_color(pos, fdf);
	scale_pos(&pos, fdf, &x1, &y1);
	render_rotation(fdf, &pos.x, &pos.y);
	render_rotation(fdf, &x1, &y1);
	if (fdf.iso)
	{
		render_isometric(fdf, &pos.x, &pos.y, pos.z);
		render_isometric(fdf, &x1, &y1, pos.z1);
	}
	x_step = x1 - pos.x;
	y_step = y1 - pos.y;
	max(&x_step, &y_step);
	while (check_inbound(pos, fdf) && ((int)(pos.x - x1) || (int)(pos.y - y1)))
	{
		my_mlx_pixel_put(&fdf, (int)pos.x + fdf.offsetx, \
		(int)pos.y + fdf.offsety, color);
		pos.x += x_step;
		pos.y += y_step;
	}
}

void	draw_lines(t_data fdf)
{
	t_pos	pos;
	int		x;
	int		y;

	y = 0;
	pos.tab_y = 0;
	while (y < fdf.map.row_nbr)
	{
		x = 0;
		pos.tab_x = 0;
		while (x < fdf.map.line[y].size)
		{
			if (x < fdf.map.line[y].size - 1)
				bresenham(pos, x + 1, y, fdf);
			if (y < fdf.map.row_nbr - 1)
				bresenham(pos, x, y + 1, fdf);
			x++;
			pos.tab_x = x;
		}
		y++;
		pos.tab_y = y;
	}
}

void	mlx_draw(t_map map)
{
	t_data	fdf;

	set_base_vals(&fdf);
	fdf.mlx = mlx_init();
	fdf.mlx_win = mlx_new_window(fdf.mlx, 1200, 675, "SynthWave");
	fdf.img = mlx_new_image(fdf.mlx, 1200, 675);
	fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bits_per_pixel, \
	&fdf.line_length, &fdf.endian);
	fdf.map = map;
	mlx_hook(fdf.mlx_win, 2, 1L << 0, get_keys, &fdf);
	mlx_hook(fdf.mlx_win, 17, 0, ft_close, &fdf);
	draw_lines(fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_win, fdf.img, 0, 0);
	mlx_loop(fdf.mlx);
}
