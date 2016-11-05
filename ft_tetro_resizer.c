/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetro_resizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:31:10 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/04 19:31:12 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static tetrimino 	*ft_extend_tetro(int n, tetrimino *tetro, int size);
static int 			ft_check_tetro_line(int num);
static tetrimino 	*ft_set_tetro(tetrimino *tetro, int a, int b, int c, int d);

tetrimino **ft_tetro_resizer(tetrimino **tetro, int size)
{
	int 	i;

	i = 0;
	while (i < size)
		ft_extend_tetro(0, tetro[i++], size);
	return (tetro);
}

static tetrimino *ft_extend_tetro(int n, tetrimino *tetro, int size)
{
	int		tab[4];
	int 	side;

	if (size <= 4)
		return (tetro);
	else
		side = ft_sqrt(ft_gridsize(size));
	tab[0] = ft_check_tetro_line(tetro->p1);
	tab[1] = ft_check_tetro_line(tetro->p2);
	tab[2] = ft_check_tetro_line(tetro->p3);
	tab[3] = ft_check_tetro_line(tetro->p4);
	while (n < 4)
	{
		if (tab[n] == -1)
			tab[n] = 0;
		if (tab[n] == -2)
			tab[n] = side - 4;
		if (tab[n] == -3)
			tab[n] = side + side - 8;
		if (tab[n] == -4)
			tab[n] = side + side + side - 12;
		n++;
	}
	return (ft_set_tetro (tetro, tab[0], tab[1], tab[2], tab[3]));
}

static tetrimino *ft_set_tetro(tetrimino *tetro, int a, int b, int c, int d)
{
	tetro->p1 = tetro->p1 + a;
	tetro->p2 = tetro->p2 + b;
	tetro->p3 = tetro->p3 + c;
	tetro->p4 = tetro->p4 + d;
	return (tetro);
}

static int ft_check_tetro_line(int num)
{
	if (num >= 0 && num <= 3)
		return (-1);
	if (num >= 4 && num <= 7)
		return (-2);
	if (num >= 8 && num <= 11)
		return (-3);
	if (num >= 12 && num <= 15)
		return (-4);
	else
		return (0);
}