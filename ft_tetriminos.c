/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 15:15:56 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/22 15:15:57 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

tetrimino *ft_tetro_set_value(tetrimino *tetro, int num)
{
	tetro->p1 += num;
	tetro->p2 += num;
	tetro->p3 += num;
	tetro->p4 += num;
	return (tetro);
}

static  tetrimino   *ft_place_to_corner(tetrimino *shape)
{
	int     index;
	int     yesno;

	index = 16;
	yesno = 1;
	while (index > 0 && yesno == 1)
	{
		if (shape->p1 == 0 || shape->p1 == 1 || shape->p1 == 2 || shape->p1 == 3)
			yesno = 0;
		else
			ft_tetro_set_value(shape, -4);
		index--;
	}
	index = 16;
	while (index > 0 && yesno == 0)
	{
		if (shape->p1 == 0 || shape->p2 == 4 || shape->p3 == 4 || shape->p3 == 8)
			yesno = 1;
		else
			ft_tetro_set_value(shape, -1);
		index--;
	}
	return (shape);
}

static tetrimino	*ft_new_tetrimino(int p1, int p2, int p3, int p4, char c)
{
	tetrimino		*tetro;

	tetro = (tetrimino*)malloc(sizeof(tetrimino));
	tetro->p1 = p1;
	tetro->p2 = p2;
	tetro->p3 = p3;
	tetro->p4 = p4;
	tetro->letter = c;
	return (tetro);
}

static tetrimino	*ft_tetro_converter(char *tetrochar, char c)
{
	tetrimino		*tetro;
	int				shape[4];
	int				coordinate;
	int				index;

	index = 0;
	coordinate = 0;
	while (*tetrochar)
	{
		if (*tetrochar == '\n')
			tetrochar++;
		if (*tetrochar == '#')
		{
			shape[index] = coordinate;
			index++;
		}
		tetrochar++;
		coordinate++;
	}
	tetro = ft_new_tetrimino(shape[0], shape[1], shape[2], shape[3], c);
	return (tetro);
}

tetrimino			**ft_tetriminos(char **split, int size)
{
	tetrimino		**shapes;
	int				index;
	char            *letter;

	shapes = (tetrimino**)malloc(sizeof(tetrimino*) * size);
	index = 0;
	letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (size > 0)
	{
		shapes[index] = ft_tetro_converter(split[index], letter[index]);
		shapes[index] = ft_place_to_corner(shapes[index]);
		size--;
		index++;
	}
	return (shapes);
}
