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
static tetrimino   	*ft_move_forward(tetrimino *t, int gridsize, int right);
static tetrimino 	*ft_move_to_left_border(tetrimino *t, int gridsize);
static	void 		ft_puttetro(tetrimino *t);

int         *ft_fillit(int *grid, tetrimino **tetriminos, int size)
{
	int     i;
	int 	gridsize;
	int 	brkpoint; // !!!

	i = 0;
	brkpoint = 10; // !!!
	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
	while (size > 0)
	{
		if (ft_check_grid_space(grid, tetriminos[i]) == 1)
			grid = ft_place_tetro(grid, tetriminos[i]);
		else
		{
			while (ft_check_grid_space(grid, tetriminos[i]) != 1 && brkpoint != 0)
			{
				//printf("no\n\n");
				ft_move_forward(tetriminos[i], gridsize, 3);
				brkpoint--;
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

static tetrimino   *ft_move_forward(tetrimino *t, int gridsize, int right)
{
	int		*br;
	int 	side;
	int 	i;
	int 	gridborder;
	int 	yesno;

	br = ft_grid_border(gridsize, right);
	side = ft_sqrt(gridsize);
	i = 0;
	gridborder = 0;
	yesno = 1;

//	for (int d = 0; d < side; d++)
//		printf("%d ", br[d]);
//	printf("\n");


	while (i < side) // проверяю правую границу
	{
		if (t->p1 == br[i] || t->p2 == br[i] || t->p3 == br[i] || t->p4 == br[i])
			gridborder++;
		i++;
	}
	if (gridborder == 0)
	{
		t->p1 += 1;
		t->p2 += 1;
		t->p3 += 1;
		t->p4 += 1;
	}
	else
	{
		ft_move_to_left_border(t, gridsize);
		t->p1 += side;
		t->p2 += side;
		t->p3 += side;
		t->p4 += side;
	}
	free (br);
	return (t);
}



static tetrimino *ft_move_to_left_border(tetrimino *t, int gridsize)
{
	int		*br;
	int 	side;
	int 	i;
	int 	counter;

	br = ft_grid_border(gridsize, 1);
	side = ft_sqrt(gridsize);
	i = 0;
	counter = 0;
	while (1)
	{
		i = 0;
		while (i < side)
		{
			if (br[i] == t->p1 || br[i] == t->p2 || br[i] == t->p3 || br[i] == t->p4)
				counter++;
			i++;
		}
		if (counter == 0)
		{
			t->p1 -= 1;
			t->p2 -= 1;
			t->p3 -= 1;
			t->p4 -= 1;
		}
		else
			break;
	}
	free(br);
	ft_puttetro(t);
	return (t);
}

static	void ft_puttetro(tetrimino *t)
{
	printf("%d ", t->p1);
	printf("%d ", t->p2);
	printf("%d ", t->p3);
	printf("%d\n", t->p4);
	printf("%c\n", t->letter);
}

//static tetrimino   *ft_move_forward(tetrimino *t, int gridsize, int right)
//{
//	int		*br;
//	int 	side;
//	int 	i;
//	int 	gridborder;
//	int 	yesno;
//
//	br = ft_grid_border(gridsize, right);
//	side = ft_sqrt(gridsize);
//	i = 0;
//	gridborder = 0;
//	yesno = 1;
//
////	for (int d = 0; d < side; d++)
////		printf("%d ", br[d]);
////	printf("\n");
//
//
//	while (i < side) // проверяю правую границу
//	{
//		if (t->p1 == br[i] || t->p2 == br[i] || t->p3 == br[i] || t->p4 == br[i])
//			gridborder++;
//		i++;
//	}
//	if (gridborder == 0)
//	{
//		t->p1 += 1;
//		t->p2 += 1;
//		t->p3 += 1;
//		t->p4 += 1;
//	}
//	else
//	{
//		br = ft_grid_border(gridsize, 4);
//		gridborder = 0;
//		i = 0;
//		while (i < side) // проверяю нижнюю границу
//		{
//			if (t->p1 == br[i] || t->p2 == br[i] || t->p3 == br[i] || t->p4 == br[i])
//				gridborder++;
//			i++;
//		}
//		if (gridborder == 0)
//		{
//			br = ft_grid_border(gridsize, 1);
//			gridborder = 0;
//			i = 0;
//			while (i < side && yesno == 1)
//			{
//				if (t->p1 != br[i] && t->p2 != br[i] && t->p3 != br[i] && t->p4 != br[i])
//				{
//					t->p1 -= 1;
//					t->p2 -= 1;
//					t->p3 -= 1;
//					t->p4 -= 1;
//				}
//				else
//				{
//					yesno = -1;
//				}
//				i++;
//			}
//		}
//		else
//		{
//			printf("no space\n");
//		}
//	}
//	free (br);
//	return (t);
//}