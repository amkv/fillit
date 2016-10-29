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
static int 			*ft_remove_tetro(int *grid, tetrimino *tetro);
static int			ft_tetro_compare(tetrimino *t1, tetrimino *t2);

//int         	*ft_fillit(int *grid, tetrimino **tetro, int size)
//{
//	int     	i;
//	int 		gridsize;
//	tetrimino	*temp;
//	int 		sizecopy;
//	int 		yesno;
//
//	i = 0;
//	yesno = 100;
//	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
//	sizecopy = size;
//	while (size > 0 && yesno > 0)
////	while (size > 0)
//	{
//		if (ft_check_grid_space(grid, tetro[i]) == 1)
//		{
//			grid = ft_place_tetro(grid, tetro[i]);
//			i++;
//			size--;
//		}
//		else
//		{
//			temp = tetro[i];
//			tetro[i] = ft_move_forward(tetro[i], gridsize);
//			yesno--;
//			if (ft_tetro_compare(temp, tetro[i]) == 1)
//			{
//
////				grid = ft_extend_grid(grid, gridsize); // расширяю grid, еще без переноса старых тетримо
////				gridsize = (sizecopy + 1) * (sizecopy + 1);
////				ft_move_to_corner(tetro[i], gridsize);
////				grid = ft_remove_tetro(grid, tetro[i - 1]);
////				i--;
//			}
//		}
//	}
//	return (grid); // не надо возвращать
//}


//int         	*ft_fillit(int *grid, tetrimino **tetro, int size)
//{
//	int 		i;
//	int 		gridsize;
//	tetrimino 	*temp;
//
//	i = 0;
//	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
//	while (size > 0)
//	{
//		if (ft_check_grid_space(grid, tetro[i]) == 1)
//		{
//			ft_place_tetro(grid, tetro[i]);
//			size--;
//			i++;
//		}
//		else
//		{
//			temp = tetro[i];
//			tetro[i] = ft_move_forward(tetro[i], gridsize);
//			if (ft_tetro_compare(temp, tetro[i]) == 1)
//			{
//				i--;
//				grid = ft_remove_tetro(grid, tetro[i]);
//				tetro[i] = ft_move_forward(tetro[i], gridsize);
//			}
//		}
//	}
//	return (grid);
//}

//int         	ft_fillit(int *grid, tetrimino **tetro, int size)
//{
//	int 		i;
//	int 		gridsize;
//	tetrimino 	*temp;
//
//	i = 0;
//	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
//
	while (tetro) {
		while () {
			if (ft_check_grid_space(grid, *tetro) == 1) {
				grid = ft_place_tetro(grid, *tetro);
				tetro++;
				if (ft_fillit(grid, tetro, size) == 1)
					return (1);
				grid = ft_remove_tetro(grid, tetro[i]);
			}
			tetro[i] = ft_move_forward(tetro[i], gridsize);

		}
		return (0);
	}
	return (1);
////
//	ft_check_grid_space(grid, tetro[i]); // return 1 - есть место, -1 - нет места
//	grid = ft_place_tetro(grid, tetro[i]); // возвращает карту с размещенным тетро
//	tetro[i] = ft_move_forward(tetro[i], gridsize); // двигает тетро слева направо, вниз - направо
//	ft_tetro_compare(tetro[i], tetro[i + 1]); // return 1 - если tetro одинаковые, -1 если разные
//	grid = ft_remove_tetro(grid, tetro[i]); // возвращает карту с очищенным (нулями) местом
//
//	return (grid);
//}

int         	*ft_fillit(int *grid, tetrimino **tetro, int size)
{
	int 		index;

	index = 0;
	while (index < size)
	{
		printf("tetro\n");
		index++;
	}

	return (grid);
}

int 			ft_simple_fillit()
{

	return (1);
}



static int     ft_check_grid_space(int *g, tetrimino *t)
{
	if (g[t->p1] == 0 && g[t->p2] == 0 && g[t->p3] == 0 && g[t->p4] == 0)
		return (1);
	else
		return (-1);
}

static int		ft_tetro_compare(tetrimino *t1, tetrimino *t2)
{
	if (t1->p1 == t2->p1 && t1->p2 == t2->p2 && t1->p3 == t2->p3 && t1->p4 == t2->p4)
		return (1);
	else
		return (-1);
}

static int 		*ft_remove_tetro(int *grid, tetrimino *tetro)
{
	grid[tetro->p1] = 0;
	grid[tetro->p2] = 0;
	grid[tetro->p3] = 0;
	grid[tetro->p4] = 0;
	return (grid);
}

static int		*ft_place_tetro(int *grid, tetrimino *tetro)
{
	grid[tetro->p1] = tetro->letter;
	grid[tetro->p2] = tetro->letter;
	grid[tetro->p3] = tetro->letter;
	grid[tetro->p4] = tetro->letter;
	return (grid);
}

static	void 	ft_puttetro(tetrimino *t)
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
