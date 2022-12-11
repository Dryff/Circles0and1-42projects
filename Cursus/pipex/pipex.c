/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:56 by colas             #+#    #+#             */
/*   Updated: 2022/12/09 10:12:41 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_err_printf/ft_printf.h"

int	exec_one(t_pipex pipex, int *fd, char **envp)
{
	char	*pathing;
	int		i;

	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (1);
	if (dup2(pipex.input, STDIN_FILENO) == -1)
		exit(1);
	close(fd[0]);
	close(fd[1]);
	close(pipex.input);
	i = 0;
	while (pipex.paths[i])
	{
		pathing = ft_strjoin(pipex.paths[i], "/");
		pathing = ft_strjoin(pathing, pipex.cmd1[0]);
		if (access(pathing, F_OK) == 0)
			if (execve(pathing, pipex.cmd1, envp) == -1)
				return (1);
		free(pathing);
		i++;
	}
	return (1);
}

int	exec_two(t_pipex pipex, int *fd, char **envp)
{
	char	*pathing;
	int		i;

	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit(1);
	if (dup2(pipex.output, STDOUT_FILENO) == -1)
		exit(1);
	close(fd[0]);
	close(fd[1]);
	close(pipex.output);
	i = 0;
	while (pipex.paths[i])
	{
		pathing = ft_strjoin(pipex.paths[i], "/");
		pathing = ft_strjoin(pathing, pipex.cmd2[0]);
		if (access(pathing, F_OK) == 0)
			if (execve(pathing, pipex.cmd2, envp) == -1)
				return (free(pathing), 1);
		free(pathing);
		i++;
	}
	return (1);
}

int	exec_hub(t_pipex pipex, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return (1);
	if (pid1 == 0)
		exec_one(pipex, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		return (1);
	if (pid2 == 0)
		exec_two(pipex, fd, envp);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

char	**get_paths(char **envp)
{
	char	*raw_paths;
	char	**paths;

	raw_paths = path_finder(envp);
	paths = ft_split(raw_paths, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_err_printf("USAGE : {InputFD} {Cmd1} {Cmd2} {OutputFD}"), 1);
	pipex.paths = get_paths(envp);
	check_hub(&pipex, argv);
	exec_hub(pipex, envp);
	return (0);
}
