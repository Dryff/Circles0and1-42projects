/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:56:28 by colas             #+#    #+#             */
/*   Updated: 2022/12/05 01:24:25 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_code(char *str)
{
	if (!ft_strncmp("USAGE", str, ft_strlen(str)))
		ft_putstr_fd("USAGE : ./pipex file1 cmd1 cmd2 file2", 2);
	if (!ft_strncmp("Inputfile", str, ft_strlen(str)))
		ft_putstr_fd("Could not open input file", 2);
	if (!ft_strncmp("Outputfile", str, ft_strlen(str)))
		ft_putstr_fd("Could not open or create output file", 2);
	if (!ft_strncmp("ft_split1", str, ft_strlen(str)))
		ft_putstr_fd("ft_split did not work properly with command 1", 2);
	if (!ft_strncmp("ft_split2", str, ft_strlen(str)))
		ft_putstr_fd("ft_split did not work properly with command 2", 2);
	if (!ft_strncmp("pipeout", str, ft_strlen(str)))
		ft_putstr_fd("Could not copy pipein to stdout", 2);
	if (!ft_strncmp("inputstdin", str, ft_strlen(str)))
		ft_putstr_fd("Could not copy input file to stdin", 2);
	if (!ft_strncmp("pipein", str, ft_strlen(str)))
		ft_putstr_fd("Could not copy pipeout to stdin", 2);
	if (!ft_strncmp("outputstdout", str, ft_strlen(str)))
		ft_putstr_fd("Could not copy output file to stdout", 2);
	exit(1);
}

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
