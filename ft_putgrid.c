/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putgrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 11:55:40 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/26 11:55:41 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int     ft_sqrt(int num)
{
	int sqr;

	sqr = 0;
	while (sqr < num)
	{
		if ((sqr * sqr) == num)
			return (sqr);
		sqr++;
	}
	return (sqr);
}

void    ft_putgrid(int *grid, int size)
{
	int index;
	int newline;

	index = 0;
	(size <= 4 ) ? (newline = 3) : (newline = size - 1);
	(size <= 4 ) ? (size = 16) : (size *= size);
	while (index < size)
	{
		//printf(" %d", grid[index]);
		(grid[index] == 0) ? ft_putchar('.') : ft_putchar(grid[index]);
//		printf("%c", grid[index]);
		if (index == newline)
		{
			printf("\n");
			if (size == 16)
				newline = newline + 4;
			else
				newline = ft_sqrt(size) + newline;
		}
		index++;
	}
}
