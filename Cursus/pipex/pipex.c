/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:56 by colas             #+#    #+#             */
/*   Updated: 2022/12/05 01:37:00 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_one(t_pipex pipex, int *fd, char **envp)
{
	char	*pathing;
	int		i;

	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (error_code("pipeout"));
	if (dup2(pipex.input, STDIN_FILENO) == -1)
		return (error_code("inputstdin"));
	close(fd[0]);
	close(fd[1]);
	close(pipex.input);
	i = 0;
	while (pipex.paths[i])
	{
		pathing = ft_strjoin(pipex.paths[i], "/");
		pathing = ft_strjoin(pathing, pipex.cmd1[0]);
		if (access(pathing, F_OK) == 0)
		{
			if (execve(pathing, pipex.cmd1, envp) == -1)
				return (perror("cmd1 couldn't be executed"), free(pathing));
		}
		free(pathing);
		i++;
	}
	perror(pipex.cmd1[0]);
	exit(1);
}

void	exec_two(t_pipex pipex, int *fd, char **envp)
{
	char	*pathing;
	int		i;

	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (error_code("pipein"));
	if (dup2(pipex.output, STDOUT_FILENO) == -1)
		return (error_code("outputstdout"));
	close(fd[0]);
	close(fd[1]);
	close(pipex.output);
	i = 0;
	while (pipex.paths[i])
	{
		pathing = ft_strjoin(pipex.paths[i], "/");
		pathing = ft_strjoin(pathing, pipex.cmd2[0]);
		if (access(pathing, F_OK) == 0)
		{
			if (execve(pathing, pipex.cmd2, envp) == -1)
				return (perror("cmd2 couldn't be executed"), free(pathing));
		}
		free(pathing);
		i++;
	}
	perror(pipex.cmd2[0]);
	exit(1);
}

int	exec_hub(t_pipex pipex, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		return (perror("Could not create pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Could not split processes with fork 1"), 1);
	if (pid1 == 0)
		exec_one(pipex, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Could not split processes with fork 2"), 1);
	if (pid2 == 0)
		exec_two(pipex, fd, envp);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	char	*raw_paths;

	if (argc != 5)
		return (error_code("USAGE"), 1);
	pipex.input = open(argv[1], O_RDONLY);
	if (pipex.input == -1)
		return (error_code("Inputfile"), 1);
	pipex.output = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex.output == -1)
		return (error_code("Outputfile"), 1);
	pipex.cmd1 = ft_split(argv[2], ' ');
	if (!pipex.cmd1)
		return (error_code("ft_split1"), 1);
	pipex.cmd2 = ft_split(argv[3], ' ');
	if (!pipex.cmd2)
		return (free_all(pipex.cmd1), error_code("ft_split2"), 1);
	raw_paths = path_finder(envp);
	pipex.paths = ft_split(raw_paths, ':');
	if (!pipex.paths)
		return (free_all(pipex.cmd1), free_all(pipex.cmd2), \
		error_code("paths"), 1);
	exec_hub(pipex, envp);
	return (free_all(pipex.cmd1), free_all(pipex.cmd2), \
	free_all(pipex.paths), 0);
}
