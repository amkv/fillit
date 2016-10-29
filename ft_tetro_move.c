/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetro_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:12:31 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/26 13:12:33 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static tetrimino 	*ft_move_to_left_border(tetrimino *t, int gridsize);
static tetrimino 	*ft_move_to_down(tetrimino *t, int gridsize);
static tetrimino 	*ft_move_to_up_border(tetrimino *t, int gridsize);

// left 1
// up 2
// right 3
// down 4

tetrimino   *ft_move_forward(tetrimino *t, int gridsize)
{
	int 	i;
	int		*br;
	int 	gridborder;

	i = 0;
	gridborder = 0;
	br = ft_grid_border(gridsize, 3);
	while (i < ft_sqrt(gridsize)) // проверяю правую границу
	{
		if (br[i] == t->p1 || br[i] == t->p2 || br[i] == t->p3 || br[i] == t->p4)
			gridborder++;
		i++;
	}
	if (gridborder == 0)
		ft_tetro_set_value(t, 1);
	else
	{
		t = ft_move_to_left_border(t, gridsize);
		t = ft_move_to_down(t, gridsize);
		if (t == NULL)
			return (NULL);
	}
	//free (br);
	return (t);
}

static tetrimino *ft_move_to_down(tetrimino *t, int gridsize)
{
	int 	i;
	int		*br;
	int 	gridborder;

	i = 0;
	gridborder = 0;
	br = ft_grid_border(gridsize, 4); // нижняя граница
	while (i < ft_sqrt(gridsize)) // проверяю нижнию границу
	{
		if (br[i] == t->p1 || br[i] == t->p2 || br[i] == t->p3 || br[i] == t->p4)
			gridborder++;
		i++;
	}
	if (gridborder == 0)
		ft_tetro_set_value(t, ft_sqrt(gridsize)); // опускаю на одну строчку вниз (вычисляя side - шаг)
	else
	{
		printf("все закончилось\n");
		return (NULL);
	}
	//free (br);
	return (t);
}

static tetrimino *ft_move_to_left_border(tetrimino *t, int gridsize)
{
	int 	i;
	int		*br;
	int 	gridborder;

	br = ft_grid_border(gridsize, 1);
	gridborder = 0;
	while (1)
	{
		i = 0;
		while (i < ft_sqrt(gridsize)) // проверяю левую границу
		{
			if (br[i] == t->p1 || br[i] == t->p2 || br[i] == t->p3 || br[i] == t->p4)
				gridborder++;
			i++;
		}
		if (gridborder == 0)
			ft_tetro_set_value(t, -1);
		else
			break;
	}
	//free(br);
	return (t);
}

static tetrimino *ft_move_to_up_border(tetrimino *t, int gridsize)
{
	int 	i;
	int		*br;
	int 	gridborder;

	br = ft_grid_border(gridsize, 2);
	gridborder = 0;
	while (1)
	{
		i = 0;
		while (i < ft_sqrt(gridsize)) // проверяю верхнюю границу
		{
			if (br[i] == t->p1 || br[i] == t->p2 || br[i] == t->p3 || br[i] == t->p4)
				gridborder++;
			i++;
		}
		if (gridborder == 0)
			ft_tetro_set_value(t, -(ft_sqrt(gridsize)));
		else
			break;
	}
	//free(br);
	return (t);
}

tetrimino *ft_move_to_corner(tetrimino *t, int gridsize)
{
	ft_move_to_up_border(t, gridsize);
	ft_move_to_left_border(t, gridsize);
	return (t);
}
