#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct  s_struct
{
    size_t intput;
    size_t output;

    char    *cmd1;
    char    *cmd2;
}               t_struct;

#endif