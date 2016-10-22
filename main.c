/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:00:43 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/12 12:00:44 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
		ft_exit_error(2);
	ft_console(argv[1]);
	//ft_ptest();
	//ft_putstr("\nABB.\nABB.\nACC.\nACC.\n\n");
	//ft_ptest();
	return (0);
}


int         *ft_grid()
{
    int     *grid;
    size_t  size;
    int     index;

    size = 16;
    index = 0;
    grid = (int*)malloc(sizeof(int) * (size + 1));

    while (size > 0)
    {
        grid[index] = 0;
        index++;
        size--;
    }
    return (grid);
}
