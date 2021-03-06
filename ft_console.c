/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_console.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:40:59 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/04 16:37:41 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_console(char *name)
{
    char		*map;
    int			size;
	int 		*grid;
	char		**split;
	tetrimino	**tetriminos;

	map = ft_readfile(name);
	size = ft_validator(map);
	split = ft_tetro_splitter(map, size);
	ft_smart_validator(split, size);
	tetriminos = ft_tetriminos(split, size);
	tetriminos = ft_tetro_resizer(tetriminos, size);
	grid = ft_newgrid(size);
	ft_fillit(0, grid, tetriminos, ft_gridsize(size), size);
	ft_putgrid(grid, size);
}

//void			ft_console(char *name)
//{
//	char		*map;
//	char		**split;
//	int			size;
//	tetrimino	**tetriminos;
//	int 		*grid;
////	int 		gridsize;
//
//	map = ft_readfile(name);
//	//ft_putstr(map);
//	size = ft_validator(map);
//	split = ft_tetro_splitter(map, size);
//	//----------------------------------------------------
//	//	int		sizeprint;
//	//	int		index;
//	//	index = 0;
//	//	sizeprint = size;
//	//	while (sizeprint-- > 0)
//	//	{
//	//	 //ft_putstr(split[index]);
//	//		ft_putstr(*(split + 0 * size + index));
//	//		ft_putstr("======\n");
//	//		index++;
//	//	}
//	//----------------------------------------------------
//	ft_smart_validator(split, size);
//	tetriminos = ft_tetriminos(split, size);
//	//-----------------------------------------------------
////		for (int d = 0; d < size; d++)
////		{
////			printf("%d", tetriminos[d]->p1);
////			printf("\t");
////			printf("%d", tetriminos[d]->p2);
////			printf("\t");
////			printf("%d", tetriminos[d]->p3);
////			printf("\t");
////			printf("%d", tetriminos[d]->p4);
////			printf("\t");
////			printf("\n");
////		}
//	//----------------------------------------------------
//	grid = ft_newgrid(size);
//	//----------------------------------------------------
////	(size < 4) ? (gridsize = 16) : (gridsize = size * size);
//
////	printf("fillit\n");
////	printf("----\n");
//	ft_fillit(0, grid, tetriminos, ft_gridsize(size));
//	ft_putgrid(grid, size);
////	printf("tetriminos: %d\n", size);
////	printf("# symbols:  %d\n", size * 4);
////	printf("gridsize:   %d\n", ft_gridsize(size));
////	printf("# sqrt:     %d\n", ft_sqrt(ft_gridsize(size)));
//
//	//----------------------------------------------------
//	//ft_putgrid(grid, size);
//	//----------------------------------------------------
//	free(map); // поднять выше там где кончается использование
//	free(grid);
//	//free(**tetriminos);
//}
