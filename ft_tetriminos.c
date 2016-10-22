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

static tetrimino         *ft_new_tetrimino(int p1, int p2, int p3, int p4)
{
	tetrimino     *tetro;

	tetro = (tetrimino*)malloc(sizeof(tetrimino));
	tetro->p1 = p1;
	tetro->p2 = p2;
	tetro->p3 = p3;
	tetro->p4 = p4;
	return (tetro);
}

static tetrimino       *ft_tetro_converter(char *tetrochar)
{
	tetrimino   *tetro;
	int         shape[4];
	int         coordinate;
	int         index;

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
	tetro = ft_new_tetrimino(shape[0], shape[1], shape[2], shape[3]);
	return (tetro);
}

tetrimino        **ft_tetriminos(char** split, int size)
{
	tetrimino    **shapes;
	int          index;

	shapes = (tetrimino**)malloc(sizeof(tetrimino) * size);
	index = 0;
	while (size > 0)
	{
		shapes[index] = ft_tetro_converter(split[index]);
		size--;
		index++;
	}
	return (shapes);
}