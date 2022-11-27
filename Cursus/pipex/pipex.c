/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:09:56 by colas             #+#    #+#             */
/*   Updated: 2022/11/27 16:06:57 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    t_struct pipe;

    pipe.input = open(argc[1], O_RDONLY);
    if (!pipe.input)
        return ("error");
    pipe.output = open(argc[1], O_RDONLY);
    if (!pipe.output)
        return ("error");
}