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

static int      ft_check_grid_space(int *g, tetrimino *t);

int         *ft_fillit(int *grid, tetrimino **tetriminos, int size)
{
	int     index;

	index = 0;
	while (size > 0)
	{
		if (ft_check_grid_space(grid, tetriminos[index]) == 1)
			printf("yes\n");
		else
			printf("no\n");
		size--;
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
