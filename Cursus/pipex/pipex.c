/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:56 by colas             #+#    #+#             */
/*   Updated: 2022/11/28 17:32:41 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exec_first(t_pipex pipex, char **envp)
{
    int fd[2];
    char *path;

    path = ft_strjoin("/bin/", pipex.cmd1[0]);
    if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_putstr_fd("ERROR1.1", 2));
	if (dup2(pipex.input, STDIN_FILENO) == -1)
		return (ft_putstr_fd("ERROR1.2", 2));
    close (fd[0]);
    close (pipex.input);
    close (fd[1]);
    execve(path, pipex.cmd1, envp);
}
void    exec_second(t_pipex pipex, char **envp)
{
    int fd[2];
    char *path;

    path = ft_strjoin("/bin/", pipex.cmd2[0]);  
    if (!dup2(fd[0], STDIN_FILENO))
		return (ft_putstr_fd("ERROR2.1", 2));
    if (!dup2(pipex.output, STDOUT_FILENO))
		return (ft_putstr_fd("ERROR2.2", 2));
    close (fd[0]);
    close (pipex.input);
    close (fd[1]);
    execve(path, pipex.cmd2, envp);

}

int exec_cmds(t_pipex pipex, char **envp)
{
    pid_t   pid1;
    pid_t   pid2;
    int     fd[2];

    // if (!access(path1, X_OK) || !access(path2, X_OK))
    //     return (free(path1), free(path2), 0);
    if (pipe(fd) == -1)
        return (0);
    pid1 = fork();
    if (pid1 == -1)
        return (0);
    if (pid1 == 0)
        exec_first(pipex, envp);
    pid2 = fork();
    if (pid2 == -1)
        return (0);
    if (pid2 == 0)
        exec_second(pipex, envp);
    return (1);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;

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
    if (!exec_cmds(pipex, envp))
        return (free_all(pipex.cmd1), free_all(pipex.cmd2), 1);
    return (0);
}