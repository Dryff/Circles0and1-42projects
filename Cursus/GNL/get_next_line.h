/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:11:24 by cgelin             #+#    #+#             */
/*   Updated: 2022/11/18 11:11:24 by cgelin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

size_t           ft_strlen(char *str);
char			 *ft_strjoin(char *s1, char *s2);
char             *get_next_line(int fd);
char             *read_file(int fd, char *backup);
int              check_end_of_line(char *backup, int read_res);
char             *ft_strchr(char *s, int c);


#endif