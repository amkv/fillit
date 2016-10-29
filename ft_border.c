/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_border.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 12:53:56 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/27 12:53:58 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		*ft_grid_border_left(int start, int end, int side)
{
	int			index;
	int			*border_left;

	index = 0;
	border_left = (int*)malloc(sizeof(int) * side);
	while (start != end + side)
	{
		border_left[index] = start;
		start += side;
		index++;
	}
	return (border_left);
}

static int		*ft_grid_border_up(int start, int side)
{
	int			index;
	int			*border_up;

	index = 0;
	border_up = (int*)malloc(sizeof(int) * side);
	while (start != side)
	{
		border_up[index] = start;
		start++;
		index++;
	}
	return (border_up);
}

static int		*ft_grid_border_right(int start, int end, int side)
{
	int			index;
	int			*border_right;

	index = 0;
	border_right = (int*)malloc(sizeof(int) * side);
	while (start != end + side)
	{
		border_right[index] = start;
		start += side;
		index++;
	}
	return (border_right);
}

static int		*ft_grid_border_down(int start, int end, int side)
{
	int			index;
	int			*border_down;

	index = 0;
	border_down = (int*)malloc(sizeof(int) * side);
	while (start != end + 1)
	{
		border_down[index] = start;
		start++;
		index++;
	}
	return (border_down);
}

int				*ft_grid_border(int gridsize, int s)
{
	int			side;
	int			border[4];

	side = ft_sqrt(gridsize);
	border[0] = 0; // левый верхний
	border[1] = side - 1; // правый верхний
	border[2] = (side * side) - side; // левый нижний
	border[3] = (side * side) - 1; // правый нижний
	if (s == 1)
		return (ft_grid_border_left(border[0], border[2], side)); // left 1
	if (s == 2)
		return (ft_grid_border_up(border[0], side)); // up 2
	if (s == 3)
		return (ft_grid_border_right(border[1], border[3], side)); // right 3
	if (s == 4)
		return (ft_grid_border_down(border[2], border[3], side)); // down 4
	return (NULL);
}
