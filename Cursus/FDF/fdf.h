/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:57:56 by colas             #+#    #+#             */
/*   Updated: 2023/01/09 15:50:45 by cgelin           ###   ########.fr       */
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

# define MAX(a, b) (a > b ? a : b)
# define ABS(a) ((a < 0) ? -a : a)

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
}				t_map;

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
	int		xy_scale;
	int		z_scale;
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

int		ft_atoi(const char *str);
t_array	ft_split_to_int(char const *s, char c);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);
void	mlx_draw(t_map map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(t_pos pos, t_data fdf);
void	render_isometric(float *x, float *y, int z);
int		ft_split_hex_color(const char *s, int i);
int		ft_close(t_data *fdf);
void	draw_lines(t_data fdf);
int		get_keys(int key, t_data *fdf);

#endif