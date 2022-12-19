/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_ps.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:39:18 by colas             #+#    #+#             */
/*   Updated: 2022/12/05 16:39:18 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PS_H
# define HEADER_PS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	int	*a_stack;
	int	*b_stack;
	int	*nb_sort;

	int	a_size;
	int	b_size;
	int	nb_size;
}				t_struct;

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlen(char *s);
void		*ft_calloc(size_t bits, size_t size_t);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_all(t_struct *ps);

t_struct	get_str(char *str);
t_struct	get_args(int argc, char **argv);
void		assign_index(t_struct *ps);
void		print_tabs(t_struct *ps);
int			check_equal(t_struct *ps);

int			general_sort(t_struct *ps);
int			sort_three(t_struct *ps);
int			sort_five(t_struct *ps);
void		binary_index_parse(t_struct *ps);
void		radix_sort(t_struct *ps);

void		sa(t_struct *ps);
void		sb(t_struct *ps);
void		ss(t_struct *ps);
void		ra(t_struct *ps);
void		rb(t_struct *ps);
void		rr(t_struct *ps);
void		rra(t_struct *ps);
void		rrb(t_struct *ps);
void		rrr(t_struct *ps);
void		pa(t_struct *ps);
void		pb(t_struct *ps);

#endif