/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:03:19 by cgelin            #+#    #+#             */
/*   Updated: 2023/01/09 15:52:04 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_data *fdf, int key)
{
	if (key == 13)
		fdf->offsety -= 10;
	if (key == 1)
		fdf->offsety += 10;
	if (key == 0)
		fdf->offsetx -= 10;
	if (key == 2)
		fdf->offsetx += 10;
	fdf->img = mlx_new_image(fdf->mlx, 1200, 675);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
	&fdf->line_length, &fdf->endian);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}

void	zoom(t_data *fdf, int key)
{
	if (key == 78)
		fdf->xy_scale -= 1;
	if (key == 69)
		fdf->xy_scale += 1;
	fdf->img = mlx_new_image(fdf->mlx, 1200, 675);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, \
	&fdf->line_length, &fdf->endian);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_E)
		fdf->cam->angle += ANGLE_INC;
	else if (key == KEY_Q)
		fdf->cam->angle -= ANGLE_INC;
	draw_wireframe(fdf);
}

int	get_keys(int key, t_data *fdf)
{
	if (key == 53)
		ft_close(fdf);
	if (key == 13 || key == 2 || key == 1 || key == 0)
		move(fdf, key);
	// if (key == 69 || key == 78)
	// 	zoom(fdf, key);
	printf("%d\n", key);
	return (0);
}
