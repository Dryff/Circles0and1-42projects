/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:37:28 by colas             #+#    #+#             */
/*   Updated: 2022/12/09 09:53:16 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_err_printf/ft_printf.h"

int	check_cmd(t_pipex *pipex, char *cmd)
{
	char	*pathing;
	int		i;

	i = 0;
	while (pipex->paths[i])
	{
		pathing = ft_strjoin(pipex->paths[i], "/");
		pathing = ft_strjoin(pathing, cmd);
		if (access(pathing, F_OK) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_fildes(t_pipex *pipex, char **argv)
{
	pipex->input = open(argv[1], O_RDONLY);
	if (pipex->input == -1)
	{
		if (access(argv[1], F_OK) == 0)
			ft_err_printf("zsh: permission denied: %s\n", argv[1]);
		else
			ft_err_printf("zsh: no such file or directory: %s\n", argv[1]);
		pipex->output = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex->output == -1)
			ft_err_printf("zsh: permission denied: %s\n", argv[4]);
	}
	else 
	{
		pipex->output = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex->output == -1)
			ft_err_printf("zsh: permission denied: %s\n", argv[4]);
	}	
	return (0);
}

int	check_hub(t_pipex *pipex, char **argv)
{	
	int	res;

	res = check_fildes(pipex, argv);
	if (pipex->input != -1)
	{
		pipex->cmd1 = ft_split(argv[2], ' ');
		if (!pipex->cmd1[0])
			return (1);
		if (check_cmd(pipex, pipex->cmd1[0]))
			ft_err_printf("zsh: command not found: %s\n", pipex->cmd1[0]);
	}	
	if (pipex->output != -1)
	{
		pipex->cmd2 = ft_split(argv[3], ' ');
		if (!pipex->cmd2[0])
			return (free_all(pipex->cmd1), 1);
		if (check_cmd(pipex, pipex->cmd2[0]))
			ft_err_printf("zsh: command not found: %s\n", pipex->cmd2[0]);
	}
	return (res);
}
