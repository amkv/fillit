/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:25:54 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/13 11:25:55 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_exit_error(int i)
{
	char	*e[18];

	e[0] = "error: no such file or read error, exit";
	e[1] = "error: file read error, exit";
	e[2] = "usage: ./fillit \"file_name\"";
	e[3] = "error: error malloc";
	e[4] = "error: bad number of characters in the line";
	e[5] = "error: bad character in the line";
	e[6] = "error: no new line between tetriminos";
	e[7] = "error: bad number of tetriminos";
	e[8] = "error: bad last line";
	e[9] = "error: bad number of #";
	e[10] = "error: bad tetrimino";
	e[11] = "error: text";
	e[12] = "error: text";
	e[13] = "error: text";
	e[14] = "error: text";
	e[15] = "error: text";
	e[16] = "error: text";
	e[17] = "error: text";
	ft_putstr(e[i]);
	ft_putchar('\n');
	/* ft_putstr("error\n");
	n = 0; */
	exit(1);
}
