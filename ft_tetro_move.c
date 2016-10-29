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

//static tetrimino   *ft_move_forward(tetrimino *tetro, int gridsize)
//{
//	int     num;
//
//	printf("gridsize %d\n", gridsize);
//	num = gridsize / 4 - 1;
//
//	if (tetro->p1 == 3 || tetro->p1 == 7 || tetro->p1 == 11 || tetro->p1 == 11)
//		return (tetro);
//	else
//	{
//		tetro->p1 += 1;
//		tetro->p2 += 1;
//		tetro->p3 += 1;
//		tetro->p4 += 1;
//	}
//	return (tetro);
//}

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
