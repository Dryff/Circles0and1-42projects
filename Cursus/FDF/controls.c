/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:03:19 by cgelin            #+#    #+#             */
/*   Updated: 2023/01/13 16:03:08 by colas            ###   ########.fr       */
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
}

void	zoom(t_data *fdf, int key)
{
	if (key == 27 && fdf->xy_scale > 0)
		fdf->xy_scale -= 0.5f;
	if (key == 24)
		fdf->xy_scale += 0.5f;
	if (key == 29)
	{
		fdf->z_scale += 0.1f;
		fdf->map.i_max += 10;
	}
	if (key == 25)
	{
		fdf->z_scale -= 0.1f;
		fdf->map.i_max -= 10;
	}
}

void	iso(int key, t_data *fdf)
{
	if (key == 34)
	{
		if (fdf->iso == 0)
		{
			fdf->iso_val = 0.5;
			fdf->iso = 1;
		}
		else if (fdf->iso_val == 0.5)
			fdf->iso_val = 0;
		else
			fdf->iso = 0;
	}
}

void	rotate(int key, t_data *fdf)
{
	if (key == 17)
		fdf->rot_val += 0.05f;
	if (key == 15)
		fdf->rot_val -= 0.05f;
}

void	colors(int key, t_data *fdf)
{
	if (key == 8)
	{
		if (fdf->theme.index == 1)
		{
			fdf->theme.color1 = 0xF27E9D;
			fdf->theme.color2 = 0xEF16F2;
			fdf->theme.color3 = 0x9D21BF;
			fdf->theme.color4 = 0x6B1F8C;
			fdf->theme.color5 = 0x261340;
			fdf->theme.index = 0;
		}
		else
		{	
			fdf->theme.color1 = 0x04D939;
			fdf->theme.color2 = 0x03A63C;
			fdf->theme.color3 = 0x027333;
			fdf->theme.color4 = 0x025939;
			fdf->theme.color5 = 0x012340;
			fdf->theme.index = 1;
		}
	}
}
