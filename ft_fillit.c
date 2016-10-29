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
static	void 		ft_puttetro(tetrimino *t);

int         *ft_fillit(int *grid, tetrimino **tetriminos, int size)
{
	int     i;
	int 	gridsize;
	tetrimino	*temp;

	i = 0;
	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
	while (size > 0)
	{
		if (ft_check_grid_space(grid, tetriminos[i]) == 1)
		{
			grid = ft_place_tetro(grid, tetriminos[i]);
			i++;
			size--;
		}
		else
		{
			//ft_puttetro(tetriminos[i]);
			temp = tetriminos[i];
			tetriminos[i] = ft_move_forward(tetriminos[i], gridsize);
			if (tetriminos[i] == NULL)
			{
				tetriminos[i] = temp;
				ft_puttetro(tetriminos[i]);
				grid = ft_extend_grid(grid, gridsize); // расширяю grid, еще без переноса старых тетримо
				ft_move_to_corner(tetriminos[i], gridsize);
			}
		}
	}
	return (grid); // не надо возвращать
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
	return (grid);
}

static	void ft_puttetro(tetrimino *t)
{
	printf("p1: %d\n", t->p1);
	printf("p2: %d\n", t->p2);
	printf("p3: %d\n", t->p3);
	printf("p4: %d\n", t->p4);
	printf("letter: %c\n\n", t->letter);
}

//	for (int d = 0; d < side; d++)
//		printf("r%d ", br[d]);
//	printf("\n");
