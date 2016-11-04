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
//static	void 		ft_puttetro(tetrimino *t);
static int 			*ft_remove_tetro(int *grid, tetrimino *tetro);
//static int			ft_tetro_compare(tetrimino *t1, tetrimino *t2);
//static int 			ft_compare_grid(int *grid1, int *grid2, int gridsize);

/*
	ft_check_grid_space(grid, tetro[i]); 				// return 1 - есть место, -1 - нет места
	ft_place_tetro(grid, tetro[i]); 					// возвращает grid с размещенным тетро
	ft_move_forward(tetro[i], gridsize); 				// двигает тетро слева направо, вниз - направо, возвращает 1 если переместился и -1 если уперся в конец карты
	ft_tetro_compare(tetro[i], tetro[i + 1]); 			// return 1 - если tetro одинаковые, -1 если разные
	ft_remove_tetro(grid, tetro[i]); 					// возвращает карту с очищенным (нулями) местом
	ft_move_to_corner(tetro[i], gridsize); 	// возвращает тетримо на нулевую позицию (левый верхний угол)
 	ft_fillit(++i, grid, tetro, gridsize);				// возвращает int значение (для рекурсии)
 	ft_sqrt(gridsize);									// возвращает int квадратный корень
 	grid = ft_extend_grid(int *grid, int gridsize);		// доделать(?): возвращает пустую карту с нулями увеличенного размера
 	ft_putgrid(grid, size);								// доделать: не печает пересозданный grid, только изначальный


 	ft_check_move(tetro[i], gridsize);
 	ft_move_forward(tetro[i], gridsize);
 	ft_check_grid_space(grid, tetro[i]);
 	ft_place_tetro(grid, tetro[i]);
 	ft_remove_tetro(grid, tetro[i]);
 	ft_move_to_corner(tetro[i], gridsize);
 	ft_fillit(++i, grid, tetro, gridsize);
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int         	ft_fillit(int i, int *grid, tetrimino **tetro, int gridsize)
{
	int 		yesno;

	while (i < ft_sqrt(gridsize))
	{
		yesno = -1;
		while (ft_check_move(tetro[i], gridsize) == 1)
		{
			if (yesno != -1)
			{
				printf("move...      %d\n", i);
				ft_move_forward(tetro[i], gridsize);
			}
			if (ft_check_grid_space(grid, tetro[i]) == 1)
			{
				printf("place...     %d\n\n", i);
				ft_place_tetro(grid, tetro[i]);
				ft_putgrid(grid, ft_sqrt(gridsize));
				printf("\n");
				if (ft_fillit(++i, grid, tetro, gridsize) == 1)
					return (1);
				else
				{
					printf("delete...    %d\n", --i);
					ft_remove_tetro(grid, tetro[i]);
				}
			}
			yesno = 1;
		}
		printf("to_corner... %d\n", i);
		ft_move_to_corner(tetro[i], gridsize);
		return (-1);
	}
	return (1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// сокращенный рабочий алгоритм

//int         	ft_fillit(int i, int *grid, tetrimino **tetro, int gridsize)
//{
//	int 		yesno;
//
////	grid = ft_extend_grid(gridsize);
//	while (i < ft_sqrt(gridsize))
//	{
//		yesno = 0;
//		while (ft_check_move(tetro[i], gridsize) == 1)
//		{
//			if (yesno++ > 0)
//				ft_move_forward(tetro[i], gridsize);
//			if (ft_check_grid_space(grid, tetro[i]) == 1)
//			{
//				ft_place_tetro(grid, tetro[i]);
//				if (ft_fillit(++i, grid, tetro, gridsize) == 1)
//					return (1);
//				ft_remove_tetro(grid, tetro[--i]);
//			}
//		}
//		ft_move_to_corner(tetro[i], gridsize);
//		return (-1);
//	}
//	return (1);
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int     ft_check_grid_space(int *g, tetrimino *t)
{
	if (g[t->p1] == 0 && g[t->p2] == 0 && g[t->p3] == 0 && g[t->p4] == 0)
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

//static	void 	ft_puttetro(tetrimino *t)
//{
//	printf("p1: %d\n", t->p1);
//	printf("p2: %d\n", t->p2);
//	printf("p3: %d\n", t->p3);
//	printf("p4: %d\n", t->p4);
//	printf("letter: %c\n\n", t->letter);
//}

//static int 		ft_compare_grid(int *grid1, int *grid2, int gridsize)
//{
//	int 	index;
//	int 	counter;
//
//	index = 0;
//	counter = 0;
//	while (index < gridsize)
//	{
//		if (grid1[index] == grid2[index])
//			counter++;
//		index++;
//	}
//	if (counter == gridsize)
//		return (1);
//	else
//		return (-1);
//}

//static int		ft_tetro_compare(tetrimino *t1, tetrimino *t2)
//{
//	if (t1->p1 == t2->p1 && t1->p2 == t2->p2 && t1->p3 == t2->p3 && t1->p4 == t2->p4)
//		return (1);
//	else
//		return (-1);
//}

//	for (int d = 0; d < side; d++)
//		printf("r%d ", br[d]);
//	printf("\n");
