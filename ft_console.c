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

void		ft_console(char *name)
{
    char	*map;
    char	**split;
    int		size;
	int 	*grid;


//	int		sizeprint;
//	int		index;

	map = ft_readfile(name);
	//ft_putstr(map);
	size = ft_validator(map);
	//ft_putstr(map);
	split = ft_tetro_splitter(map, size);
	ft_smart_validator(split, size);
	grid = ft_grid();

//	for (int m = 0; m < 16; m++)
//		printf("%d\n", grid[m]);

//	index = 0;
//	sizeprint = size;
//	while (sizeprint-- > 0)
//	{
//	 //ft_putstr(split[index]);
//		ft_putstr(*(split + 0 * size + index));
//		ft_putstr("======\n");
//		index++;
//	}
//    printf("tetriminos: %d\n", size);
	free(map);
}
