/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:00:49 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/01 01:11:29 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	fill_input(t_input *input, int argc, char *argv[])
{
	int		i;

	input->bench = 0;
	input->algorithm_complexity = 0;
	i = 1;
	while (i <= argc)
	{
		if (!ft_strncmp(argv[i], "--", 2))
		{
			if (!ft_strncmp(argv[i++], "--bench", 8)) //check if size+1 checks for end
				input->bench = 1;
			if (!ft_strncmp(argv[i++], "--simple", 9))
				input->algorithm_complexity = 1;
			else if (!ft_strncmp(argv[i++], "--medium", 9))
				input->algorithm_complexity = 2;
			else if (!ft_strncmp(argv[i++], "--complex", 10))
				input->algorithm_complexity = 3;
			else if (!ft_strncmp(argv[i++], "--adaptive", 11))
				input->algorithm_complexity = 0;
		}
		else
			//fill_input_arr(input, argv, argc, i);
		}
}
/*
void	fill_input_arr(t_input *input, char *strings[], int n, int i)
{
	char	**str_args;

	str_args = ft_split(
}*/
