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

	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
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

int 		*ft_extend_grid(int *grid, int gridsize)
{
	int 	side;
	int 	newside;
	int 	newgridsize;
	int 	*newgrid;
	int 	index;

	index = 0;
	side = ft_sqrt(gridsize);
	newside = side + 1;
	newgridsize = newside * newside;
	newgrid = (int*)malloc(sizeof(int) * newgridsize);
	while (index < newgridsize)
	{
		newgrid[index] = 0;
		//newgrid[index] = grid[index];
		index++;
	}

	free(grid);
	return (newgrid);
}
