/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:57:56 by colas             #+#    #+#             */
/*   Updated: 2023/01/13 15:54:06 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "ft_err_printf/ft_printf.h"
# include "GNL/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_array
{
	int		*arr;
	int 	*color;
	int		size;
}				t_array;

typedef struct s_map
{
	t_array	*line;
	int		row_nbr;
	int		i_max;
	int		i_min;
}				t_map;

typedef struct s_theme
{
	int color1;
	int color2;
	int color3;
	int color4;
	int color5;
	int index;
}				t_theme;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	t_map	map;

	int		offsety;
	int		offsetx;
	float	xy_scale;
	float	z_scale;
	int		iso;
	float	iso_val;
	float	iso_tmp;
	float	rot_val;
	t_theme	theme;

}				t_data;

typedef struct s_pos
{
	float	x;
	float	y;
	int		z;
	int		z1;
	int		tab_x;
	int		tab_y;

	int		color;
	int		gradient;
}				t_pos;

//Parse
t_array	ft_split_to_int(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);

//Drawing
void	draw_lines(t_data fdf);
void	mlx_draw(t_map map);
int		get_keys(int key, t_data *fdf);

//Drawing_utils
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(t_pos pos, t_data fdf);
void	render_isometric(t_data fdf, float *x, float *y, int z);
void	render_rotation(t_data fdf, float *x, float *y);
void	max(float *x_step, float *y_step);

//Controls
int		ft_close(t_data *fdf);
void	move(t_data *fdf, int key);
void	zoom(t_data *fdf, int key);
void	iso(int key, t_data *fdf);
void	rotate(int key, t_data *fdf);
void	colors(int key, t_data *fdf);

//Assign values
void	scale_pos(t_pos *pos, t_data fdf, float *x1, float *y1);
void	assign_pos(t_pos *pos, t_data fdf, float *x1, float *y1);
void	set_base_vals(t_data *fdf);




#endif