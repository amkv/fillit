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

static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size);
static int 		ft_check_the_grid(const int *grid, const tetrimino *tetriminos);

int				*ft_grid(tetrimino **tetriminos, int size)
{
	int		*grid;
	size_t	freshsize;
	int		index;

	freshsize = 16;
	index = 0;
	grid = (int*)malloc(sizeof(int) * freshsize);
	while (freshsize > 0)
	{
		grid[index] = 0;
		index++;
		freshsize--;
	}
	grid = ft_fill_grid(grid, tetriminos, size);
	return (grid);
}

static int 		*ft_fill_grid(int *grid, tetrimino **tetriminos, int size)
{
	int 		amount;
	int 		index;

	amount = 0;
	while (amount < size)
	{
		index = 0;
		if (ft_check_the_grid(grid, tetriminos[amount]) == 1)
		{
			printf("yes\n");
			if (tetriminos[amount]->p1 == index)
				grid[index] = 1;
			if (tetriminos[amount]->p2 == index)
				grid[index] = 1;
			if (tetriminos[amount]->p3 == index)
				grid[index] = 1;
			if (tetriminos[amount]->p4 == index)
				grid[index] = 1;
		}
		else
			printf("%s\n", "no");
		amount++;
	}
	return (grid);
}

static int 		ft_check_the_grid(const int *grid, const tetrimino *tetriminos)
{
	int 	index;
	int 	yesno;

	yesno = 0;
	index = 0;
	while (index < 16)
	{
		if (tetriminos->p1 == index)
			if (grid[index] == 1)
				yesno++;
		if (tetriminos->p2 == grid[index])
			if (grid[index] == 1)
				yesno++;
		if (tetriminos->p3 == grid[index])
			if (grid[index] == 1)
				yesno++;
		if (tetriminos->p4 == grid[index])
			if (grid[index] == 1)
				yesno++;
		index++;
	}
	if (yesno == 0)
		return (1); // на карту можно наносить тетринимо
	else
		return (0); // на карту нельзя наносить тетринимо
}

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


