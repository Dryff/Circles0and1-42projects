/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:56 by colas             #+#    #+#             */
/*   Updated: 2022/11/28 23:05:10 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exec_first(t_pipex pipex, int *fd)
{
    char *pathing;
    int i;

    if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_putstr_fd("ERROR1.1", 2));
	if (dup2(pipex.input, STDIN_FILENO) == -1)
		return (ft_putstr_fd("ERROR1.2", 2));
    close (fd[0]);
    close (fd[1]);
    close (pipex.input);
    i = 0;
    while (pipex.paths[i])
	{
		pathing = ft_strjoin(pipex.paths[i], "/");
		pathing = ft_strjoin(pathing, pipex.cmd1[0]);
		if (access(pathing, F_OK) == 0)
		{
			if (execve(pathing, pipex.cmd1, NULL) == -1)
				return (ft_putstr_fd("ERROR of paths", 2));
		}
		free(pathing);
		i++;
	}
}
void    exec_second(t_pipex pipex, int *fd)
{
    char *pathing;
    int i;

    if (dup2(fd[0], STDIN_FILENO) == -1)
		return (ft_putstr_fd("ERROR2.1", 2));
    if (dup2(pipex.output, STDOUT_FILENO) == -1
    )
		return (ft_putstr_fd("ERROR2.2", 2));
    close (fd[0]);
    close (fd[1]);
    close (pipex.output);
    i = 0;
    while (pipex.paths[i])
	{
		pathing = ft_strjoin(pipex.paths[i], "/");
		pathing = ft_strjoin(pathing, pipex.cmd2[0]);
		if (access(pathing, F_OK) == 0)
		{
			if (execve(pathing, pipex.cmd2, NULL) == -1)
				return (ft_putstr_fd("ERROR of paths", 2));
		}
		free(pathing);
		i++;
	}
}

int exec_cmds(t_pipex pipex)
{
    pid_t   pid1;
    pid_t   pid2;
    int     fd[2];

    if (pipe(fd) == -1)
        return (0);
    pid1 = fork();
    if (pid1 == -1)
        return (0);
    if (pid1 == 0)
        exec_first(pipex, fd);
    pid2 = fork();
    if (pid2 == -1)
        return (0);
    if (pid2 == 0)
        exec_second(pipex, fd);
    return (1);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;
    char    *raw_paths;

    if (argc != 5)
        return (ft_putstr_fd("USAGE : ./pipex file1 cmd1 cmd2 file2 ", 2), 1);
    pipex.input = open(argv[1], O_RDONLY);
    if (pipex.input == -1)
        return (ft_putstr_fd("ERROR : Input file isn't readable", 2), 1);
    pipex.output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (pipex.output == -1)
        return (ft_putstr_fd("ERROR : Output file cannot be created", 2), 1);
    pipex.cmd1 = ft_split(argv[2], ' ');
    pipex.cmd2 = ft_split(argv[3], ' ');
    raw_paths = path_finder(envp);
	pipex.paths = ft_split(raw_paths, ':');
    if (!exec_cmds(pipex))
        return (free_all(pipex.cmd1), free_all(pipex.cmd2), 1);
    return (0);
}