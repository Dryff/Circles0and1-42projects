/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:34:04 by colas             #+#    #+#             */
/*   Updated: 2023/01/13 15:56:21 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_pos(t_pos *pos, t_data fdf, float *x1, float *y1)
{
	pos->x *= fdf.xy_scale;
	pos->y *= fdf.xy_scale;
	pos->z *= fdf.xy_scale;
	pos->z1 *= fdf.xy_scale;
	*x1 *= (float)fdf.xy_scale;
	*y1 *= (float)fdf.xy_scale;
}

void	assign_pos(t_pos *pos, t_data fdf, float *x1, float *y1)
{
	pos->z = fdf.map.line[pos->tab_y].arr[pos->tab_x] * fdf.z_scale;
	pos->z1 = fdf.map.line[(int)*y1].arr[(int)*x1] * fdf.z_scale;
	pos->x = pos->tab_x - (fdf.map.line->size / 2);
	pos->y = pos->tab_y - (fdf.map.row_nbr / 2);
	*x1 -= (fdf.map.line->size / 2);
	*y1 -= (fdf.map.row_nbr / 2);
}

void	set_base_vals(t_data *fdf)
{
	fdf->offsetx = 570;
	fdf->offsety = 400;
	fdf->xy_scale = 1;
	fdf->z_scale = 0.5;
	fdf->iso = 1;
	fdf->iso_val = 0.5;
	fdf->rot_val = 0;
	fdf->theme.color1 = 0xF27E9D;
	fdf->theme.color2 = 0xEF16F2;
	fdf->theme.color3 = 0x9D21BF;
	fdf->theme.color4 = 0x6B1F8C;
	fdf->theme.color5 = 0x261340;
}
