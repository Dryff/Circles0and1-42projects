/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:47:18 by colas             #+#    #+#             */
/*   Updated: 2023/01/04 10:50:36 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_isometric(float *x, float *y, int z)
{
	(void) z;
	*x = (*x - *y) * cos(0.7);
	*y = (*y + *x) * sin(0.7) - z;
}

// static int	ft_lerp(int first, int second, double p)
// {
// 	if (first == second)
// 		return (first);
// 	return ((int)((double)first + (second - first) * p));
// }

// int	ft_get_color(t_pos pos, t_data fdf)
// {
// 	int		r;
// 	int		g;
// 	int		b;
// 	float	percent;

// 	(void)fdf;
// 	(void)pos;
// 	percent = 0;
// 	r = ft_lerp((0x00FF0000 >> 16) & 0xFF, (0x000000FF >> 16) & 0xFF, percent);
// 	g = ft_lerp((0x00FF0000 >> 8) & 0xFF, (0x000000FF >> 8) & 0xFF, percent);
// 	b = ft_lerp(0x00FF00 & 0xFF, 0x000000FF & 0xFF, percent);
// 	r *= 10;
// 	g *= 10;
// 	b *= 10;
// 	return ((r << 16) | (g << 8) | b);
// }
