/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newgrid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 11:03:04 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/24 11:03:10 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



int				*ft_newgrid(int size)
{
	int		    *grid;
	int		    index;
	int         gridsize;

//	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
	gridsize = ft_gridsize(size);
	index = 0;
	grid = (int*)malloc(sizeof(int) * gridsize);
	while (gridsize > 0)
	{
		grid[index] = 0;
		index++;
		gridsize--;
	}
	return (grid);
}



int 		*ft_extend_grid(int gridsize)
{
	int 	side;
	int 	newside;
	int 	newgridsize;
	int 	*newgrid;
	int 	index;

	index = 0;
	side = ft_sqrt(gridsize);
	printf("old_side: %d\n", side);
	newside = side + 1;
	printf("new_side: %d\n", newside);
	printf("old_gridsize: %d\n", gridsize);
	newgridsize = newside * newside;
	printf("new_gridsize: %d\n", newgridsize);
	newgrid = (int*)malloc(sizeof(int) * newgridsize);
	while (index < newgridsize)
	{
		newgrid[index] = 0;
		//newgrid[index] = grid[index];
		index++;
	}

//	free(grid);
	return (newgrid);
}

int     ft_sqrt(int num)
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

int ft_gridsize(int size)
{
	int gridsize;
	int symb;

	if (size <= 4)
		gridsize = 16;
	else
	{
		symb = size * 4;
		while ((size * size) >= symb)
			size--;
		size++;
		gridsize = size * size;
	}
//	printf("gridsize = %d\n", gridsize);
	return (gridsize);
}

void    ft_putgrid(int *grid, int size)
{
	int index;
	int newline;
	int gridsize;

	index = 0;

//	(size <= 4 ) ? (size = 16) : (size *= size);
	gridsize = ft_gridsize(size);
	(size <= 4 ) ? (newline = 3) : (newline = ft_sqrt(gridsize) - 1);
	while (index < gridsize)
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
				newline = ft_sqrt(gridsize) + newline;
		}
		index++;
	}
}
