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


// left 2
// up 2
// right 3
// down 4

// if (tetro->p1 != br[0] || tetro->p2 != br[1] || tetro->p3 != br[2] tetro->p4 != br[3])

//static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size)
//{
//	int 		amount;
//	int 		index;
//	int         gridsize;
//
//	amount = 0;
//
//	(size <= 4 ) ? (gridsize = 16) : (gridsize = size * size);
//	while (amount < size)
//	{
//		index = 0;
//		if (ft_check_the_grid(grid, tetriminos[amount], size) == 1)
//		{
//			while (index < gridsize)
//			{
//				if (tetriminos[amount]->p1 == index)
//					grid[index] = tetriminos[amount]->letter;
//				if (tetriminos[amount]->p2 == index)
//					grid[index] = tetriminos[amount]->letter;
//				if (tetriminos[amount]->p3 == index)
//					grid[index] = tetriminos[amount]->letter;
//				if (tetriminos[amount]->p4 == index)
//					grid[index] = tetriminos[amount]->letter;
//				index++;
//			}
//		}
//		else
//		{
//			printf("no\n");
//		}
//		amount++;
//	}
//	return (grid);
//}

//int             ft_check_the_grid(int *grid, tetrimino *tetriminos, int size)
//{
//	grid = NULL;
//	tetriminos = NULL;
//	size = 0;
//	return (1);
//}

//static int      ft_place_tetrimino(tetrimino tetro, )

//static int 		ft_check_the_grid(const int *grid, const tetrimino *tetriminos)
//{
//	int 	index;
//	int 	yesno;
//
//	yesno = 0;
//	index = 0;
//	while (index < 16)
//	{
//		if (tetriminos->p1 == index)
//			if (grid[index] == 1)
//				yesno++;
//		if (tetriminos->p2 == grid[index])
//			if (grid[index] == 1)
//				yesno++;
//		if (tetriminos->p3 == grid[index])
//			if (grid[index] == 1)
//				yesno++;
//		if (tetriminos->p4 == grid[index])
//			if (grid[index] == 1)
//				yesno++;
//		index++;
//	}
//	if (yesno == 0)
//		return (1); // на карту можно наносить тетринимо
//	else
//		return (0); // на карту нельзя наносить тетринимо
//}
