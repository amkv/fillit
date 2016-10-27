/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:40:59 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/13 12:41:01 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_console(char *name)
{
    char		*map;
    char		**split;
    int			size;
	tetrimino	**tetriminos;
	int 		*grid;

	map = ft_readfile(name);
	//ft_putstr(map);

	size = ft_validator(map);
	split = ft_tetro_splitter(map, size);
	//----------------------------------------------------
	//	int		sizeprint;
	//	int		index;
	//	index = 0;
	//	sizeprint = size;
	//	while (sizeprint-- > 0)
	//	{
	//	 //ft_putstr(split[index]);
	//		ft_putstr(*(split + 0 * size + index));
	//		ft_putstr("======\n");
	//		index++;
	//	}
	//----------------------------------------------------
	ft_smart_validator(split, size);
	tetriminos = ft_tetriminos(split, size);
	//-----------------------------------------------------
//		for (int d = 0; d < size; d++)
//		{
//			printf("%d", tetriminos[d]->p1);
//			printf("\t");
//			printf("%d", tetriminos[d]->p2);
//			printf("\t");
//			printf("%d", tetriminos[d]->p3);
//			printf("\t");
//			printf("%d", tetriminos[d]->p4);
//			printf("\t");
//			printf("\n");
//		}
	//----------------------------------------------------
	grid = ft_grid(tetriminos, size);
	//----------------------------------------------------
//	printf("%d\n", grid[1000]);

	ft_putgrid(grid, size);
//	printf("tetriminos: %d\n", size);
	free(map);
	free(grid);
}
