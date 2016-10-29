/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:39:35 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/27 15:39:37 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int      	ft_check_grid_space(int *g, tetrimino *t);
static int			*ft_place_tetro(int *grid, tetrimino *tetro);
static tetrimino   	*ft_move_right(tetrimino *t, int gridsize, int right);

int         *ft_fillit(int *grid, tetrimino **tetriminos, int size)
{
	int     i;
	int 	gridsize;
	int 	yesno;

	i = 0;
	yesno = 1;
	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
	while (size > 0)
	{
		if (ft_check_grid_space(grid, tetriminos[i]) == yesno)
		{
			printf("yes\n");
			grid = ft_place_tetro(grid, tetriminos[i]);
		}
		else
		{
			while (ft_check_grid_space(grid, tetriminos[i]) != yesno)
			{
				printf("no\n");
				ft_move_right(tetriminos[i], gridsize, 3);
				yesno = -1;
			}
			grid = ft_place_tetro(grid, tetriminos[i]);
		}
		size--;
		i++;
	}
	return (grid);
}

static int     ft_check_grid_space(int *g, tetrimino *t)
{
	if (g[t->p1] == 0 && g[t->p2] == 0 && g[t->p3] == 0 && g[t->p4] == 0)
		return (1);
	else
		return (-1);
}

static int		*ft_place_tetro(int *grid, tetrimino *tetro)
{
	grid[tetro->p1] = tetro->letter;
	grid[tetro->p2] = tetro->letter;
	grid[tetro->p3] = tetro->letter;
	grid[tetro->p4] = tetro->letter;
//
// 	grid[tetro->p1] = 'a';
//	grid[tetro->p2] = 'b';
//	grid[tetro->p3] = 'c';
//	grid[tetro->p4] = 'd';

	return (grid);
}

static tetrimino   *ft_move_right(tetrimino *t, int gridsize, int right)
{
	int		*br;
	int 	side;
	int 	i;

	br = ft_grid_border(gridsize, right);
	side = ft_sqrt(gridsize);
	i = 0;
//	while (i < side)
//	{
//		printf("%d ", br[i]);
//		i++;
//	}
//	printf("\n");

//	if (t->p1 + 1 != br[i] && t->p2 + 1 != br[i] && t->p3 + 1 != br[i] && t->p4 + 1 != br[i])
//	{
		t->p1 += 1;
		t->p2 += 1;
		t->p3 += 1;
		t->p4 += 1;
//	}
//	else
//		return (t);
	free (br);
	return (t);
}