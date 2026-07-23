/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:55:31 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:55:31 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_recur(long x, int fd)
{
	if (x > 9)
		ft_putnbr_fd_recur(x / 10, fd);
	ft_putchar_fd(x % 10 + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar_fd('-', fd);
		x = -x;
	}
	ft_putnbr_fd_recur(x, fd);
}
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc != 2)
		return 0;
	ft_putnbr_fd(ft_atoi(argv[1]), 1);
}
*/
