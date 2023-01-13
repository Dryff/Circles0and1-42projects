/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:47:18 by colas             #+#    #+#             */
/*   Updated: 2023/01/13 15:50:27 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_isometric(t_data fdf, float *x, float *y, int z)
{
	*x = (*x - *y) * cos(fdf.iso_val);
	*y = (*y + *x) * sin(fdf.iso_val) - z;
}

void	render_rotation(t_data fdf, float *x, float *y)
{
	float	base_x;
	float	base_y;

	base_x = *x;
	base_y = *y;
	*x = (base_x * cos(fdf.rot_val)) - (base_y * sin(fdf.rot_val));
	*y = (base_x * sin(fdf.rot_val)) + (base_y * cos(fdf.rot_val));
}

int	get_color(t_pos pos, t_data fdf)
{
	float	percent1;
	float	percent2;

	fdf.map.i_max /= 2;
	percent1 = (float)pos.z / (float)fdf.map.i_max;
	percent2 = (float)pos.z1 / (float)fdf.map.i_max;
	if (percent1 >= 0.7 && percent2 >= 0.7)
		return (fdf.theme.color1);
	else if (percent1 >= 0.5 && percent2 >= 0.5)
		return (fdf.theme.color2);
	else if (percent1 >= 0.2 && percent2 >= 0.2)
		return (fdf.theme.color3);
	else if (percent1 >= 0.01 && percent2 >= 0.01)
		return (fdf.theme.color4);
	return (fdf.theme.color5);
}

void	max(float *x_step, float *y_step)
{
	int		max;

	max = fmax(fabs(*x_step), fabs(*y_step));
	*x_step /= max;
	*y_step /= max;
}
