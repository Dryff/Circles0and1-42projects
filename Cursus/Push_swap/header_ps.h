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

#ifndef HEADER_PS
# define HEADER_PS

#include <stdlib.h>
#include <unistd.h>

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif