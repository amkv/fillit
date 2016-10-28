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

static int      ft_check_grid_space(int *g, tetrimino *t);
static int		*ft_place_tetro(int *grid, tetrimino *tetro);
static tetrimino   *ft_move_right(tetrimino *tetro);

int         *ft_fillit(int *grid, tetrimino **tetriminos, int size)
{
	int     i;

	i = 0;
	while (size > 0)
	{
		if (ft_check_grid_space(grid, tetriminos[i]) == 1)
		{
			printf("yes\n");
			grid = ft_place_tetro(grid, tetriminos[i]);
		}
		else
		{
			while (ft_check_grid_space(grid, tetriminos[i]) != 1)
			{
				printf("no\n");
				ft_move_right(tetriminos[i]);
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
	return (grid);
}

static tetrimino   *ft_move_right(tetrimino *tetro)
{
	tetro->p1 += 1;
	tetro->p2 += 1;
	tetro->p3 += 1;
	tetro->p4 += 1;
	return (tetro);
}