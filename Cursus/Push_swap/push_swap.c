/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colas <colas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:30:38 by colas             #+#    #+#             */
/*   Updated: 2022/12/05 20:10:42 by colas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h" 

void	assign_index(int *nbrs)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 1;
	while (nbrs[i])
	{
		while (nbrs[j])
		{
			if (nbrs[j] < nbrs[i])
			{
				temp = nbrs[i];
				nbrs[i] = nbrs[j];
				nbrs[j] = temp;
			}
			j++;
		}
		i++;
	}
	nbrs[i] = 0;
}

int	*check_and_convert(int argc, char **argv)
{
	int i;
	int j;
	int *nbrs;

	nbrs = malloc(sizeof(int*) * argc);
	if (!nbrs)
		return(NULL);
	if (argc < 2)
			return (ft_putstr_fd("Usage : ./push_swap int1 int2 int3... intn", 2), NULL);
		i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_putstr_fd("Usage : ./push_swap int1 int2 int3... intn", 2), NULL);
			nbrs[i] = ft_atoi(argv[i]);
			j++;
		}
	i++;
	}
	return (nbrs);
}

int	main(int argc, char	**argv)
{

	int *nbrs;
	
	nbrs = check_and_convert(argc, argv);
	
	// nbrs_index = malloc(sizeof(int) * argc)
	// nbrs_index = assign_index(&argv[1]);
}