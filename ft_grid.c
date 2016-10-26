/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 11:03:04 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/24 11:03:10 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size, int gridsize);
//static int 		ft_check_the_grid(const int *grid, const tetrimino *tetriminos);
int                 ft_check_the_grid(int *grid, tetrimino *tetriminos, int size, int gridsize);
static tetrimino   *ft_move_right(tetrimino *tetro, int gridsize);
//static tetrimino   *ft_move_left(tetrimino *tetro);
//static tetrimino   *ft_move_up(tetrimino *tetro);
//static tetrimino   *ft_move_down(tetrimino *tetro);

int				*ft_grid(tetrimino **tetriminos, int size)
{
	int		*grid;
	int	    gridsize;
	int		index;
	int     temp;

	gridsize = size * size;
	if (gridsize <= 16)
		gridsize = 16;
	temp = gridsize;
	index = 0;
	grid = (int*)malloc(sizeof(int) * temp);
	while (temp > 0)
	{
		grid[index] = 0;
		index++;
		temp--;
	}
	grid = ft_fill_grid(grid, tetriminos, size, gridsize);
	return (grid);
}

//static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size, int gridsize)
//{
//
//	while (size > 0)
//	{
//
//		size--;
//	}
//
//
//
//	return (grid);
//}

//static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size, int gridsize)
//{
//	if (size > 0)
//	{
//		определяю есть ли свободное место для данного тетринимо
//			засылаю Сетку, тетринимо и размер сетки
//		проверяю свободное место для данного типа фигуры
//		если свободное место есть, то
//
//			двигаю тетринимо до тех пор, пока не упрусь в левый верхний угол
//
//
//	}
//	else
//		return (grid);
//}



//static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size, int gridsize)
//{
//	int 		amount;
//	int 		index;
//
//	amount = 0;
//	while (amount < size)
//	{
//		index = 0;
//		if (ft_check_the_grid(grid, tetriminos[amount], size, gridsize) == 1)
//		{
//			while (index < gridsize)
//			{
//				if (tetriminos[amount]->p1 == index)
//					grid[index] = grid[index] + 1;
//				if (tetriminos[amount]->p2 == index)
//					grid[index] = grid[index] + 1;
//				if (tetriminos[amount]->p3 == index)
//					grid[index] = grid[index] + 1;
//				if (tetriminos[amount]->p4 == index)
//					grid[index] = grid[index] + 1;
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

static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size, int gridsize)
{
	int 		amount;
	int 		index;

	amount = 0;
	while (amount < size)
	{
		index = 0;
		if (ft_check_the_grid(grid, tetriminos[amount], size, gridsize) == 1)
		{
			while (index < gridsize)
			{
				if (tetriminos[amount]->p1 == index)
					grid[index] = tetriminos[amount]->letter;
				if (tetriminos[amount]->p2 == index)
					grid[index] = tetriminos[amount]->letter;
				if (tetriminos[amount]->p3 == index)
					grid[index] = tetriminos[amount]->letter;
				if (tetriminos[amount]->p4 == index)
					grid[index] = tetriminos[amount]->letter;
				index++;
			}
		}
		else
		{
			printf("no\n");
		}
		amount++;
	}
	return (grid);
}

int             ft_check_the_grid(int *grid, tetrimino *tetriminos, int size, int gridsize)
{
	grid = NULL;
	tetriminos = NULL;
	size = 0;
	gridsize = 0;
	return (1);
}

static tetrimino   *ft_move_right(tetrimino *tetro, int gridsize)
{
	int     num;

	printf("gridsize %d\n", gridsize);
	num = gridsize / 4 - 1;

	if (tetro->p1 == 3 || tetro->p1 == 7 || tetro->p1 == 11 || tetro->p1 == 11)
		return (tetro);
	else
	{
		tetro->p1 += 1;
		tetro->p2 += 1;
		tetro->p3 += 1;
		tetro->p4 += 1;
	}
	return (tetro);
}

//static tetrimino   *ft_move_left(tetrimino *tetro)
//{
//	if (tetro->p1 == 0 || tetro->p1 == 4 || tetro->p1 == 8 || tetro->p1 == 12)
//		return (tetro);
//	else
//	{
//		tetro->p1 -= 1;
//		tetro->p2 -= 1;
//		tetro->p3 -= 1;
//		tetro->p4 -= 1;
//	}
//	return (tetro);
//}
//
//static tetrimino   *ft_move_up(tetrimino *tetro)
//{
//	if (tetro->p1 == 0 || tetro->p1 == 1 || tetro->p1 == 2 || tetro->p1 == 3)
//		return (tetro);
//	else
//	{
//		tetro->p1 -= 4;
//		tetro->p2 -= 4;
//		tetro->p3 -= 4;
//		tetro->p4 -= 4;
//	}
//	return (tetro);
//}
//
//static tetrimino   *ft_move_down(tetrimino *tetro)
//{
//	if (tetro->p1 == 0 || tetro->p1 == 1 || tetro->p1 == 2 || tetro->p1 == 3)
//		return (tetro);
//	else
//	{
//		tetro->p1 += 4;
//		tetro->p2 += 4;
//		tetro->p3 += 4;
//		tetro->p4 += 4;
//	}
//	return (tetro);
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

/*
  cоздать основную сетку размером в 16 клеток
заполнить сетку первым тетринимо
	поместить первый тетринимо как можно ближе к левому верхнему углу
поместить второй тетринимо, проверив сетку на доступность размещения второго тетринимо
	подвинуть тетринимо для того чтобы он вместился в сетку
если размер сетки недостаточек для размещения тетрнимо
	создать дополнительные поля для клетки
	переписать все тетринимо и запомнить для них новые значения
 */


