/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <nfil@student.42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:00:39 by nfil              #+#    #+#             */
/*   Updated: 2026/08/05 00:30:13 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flags_input(t_input *input, int argc, char *argv[])
{
	int		i;

	input->bench = 0;
	input->algorithm_complexity = 0;
	i = 1;
	while (i < argc && !ft_strncmp(argv[i], "--", 2))
	{
		if (!ft_strncmp(argv[i], "--bench", 8))
			input->bench = 1;
		if (!ft_strncmp(argv[i], "--simple", 9))
			input->algorithm_complexity = 1;
		else if (!ft_strncmp(argv[i], "--medium", 9))
			input->algorithm_complexity = 2;
		else if (!ft_strncmp(argv[i], "--complex", 10))
			input->algorithm_complexity = 3;
		i++;
	}
	return (i);
}

void	fill_input(t_input *input, int argc, char *argv[])
{
	int	start;
	int	remaining;

	start = flags_input(input, argc, argv);
	remaining = argc - start;
	if (remaining == 1)
		fill_input_split(input, argv[start]);
	else if (remaining > 1)
		fill_from_args(input, argc, argv, start);
}

void	fill_input_split(t_input *input, char *str)
{
	char	**splat;
	int		count;
	int		j;

	splat = ft_split(str, ' ');
	count = 0;
	while (splat[count])
		count++;
	input->arr_len = count;
	input->init_arr = malloc(sizeof(int) * count);
	if (input->init_arr == NULL)
		return ;
	j = -1;
	while (++j < count)
		input->init_arr[j] = ft_atoi(splat[j]);
}

void	fill_from_args(t_input *input, int argc, char *argv[], int start)
{
	int	count;
	int	j;

	count = argc - start;
	input->arr_len = count;
	input->init_arr = malloc(sizeof(int) * count);
	if (!(input->init_arr))
		return ;
	j = -1;
	while (++j < count)
		input->init_arr[j] = ft_atoi(argv[start + j]);
}
