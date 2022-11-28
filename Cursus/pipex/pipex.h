#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

typedef struct  s_pipex
{
    int input;
    int output;

    char    **cmd1;
    char    **cmd2;
    char    **paths;

}               t_pipex;

size_t      ft_strlen(char *s);
void        ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
void        free_all(char **strs);
char        *ft_strjoin(char const *s1, char const *s2);
char        *path_finder(char **envp);

#endif