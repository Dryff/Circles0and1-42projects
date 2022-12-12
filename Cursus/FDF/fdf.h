/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:57:56 by colas             #+#    #+#             */
/*   Updated: 2022/12/12 18:04:12 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx/mlx.h"
#include "ft_err_printf/ft_printf.h"
#include "GNL/get_next_line.h"
#include <fcntl.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	int	x;
	int y;
}				t_point;

typedef struct s_array
{
	int	*arr;
	int	size;
}				t_array;

typedef struct s_map
{
	t_array *line;
	int row_nbr;
}				t_map;

int		ft_atoi(const char *str);
t_array	ft_split_to_int(char const *s, char c);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);
void	mlx_draw(t_map map);

#endif