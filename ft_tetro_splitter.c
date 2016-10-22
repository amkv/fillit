/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetro_splitter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:24:29 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/13 11:24:30 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tetro_splitter(char *str, int size)
{
	char	**split;
	int		index;
	int		chr;

	index = 0;
	chr = 20;
	if (!(split = (char**)malloc(sizeof(char*) * size)))
		ft_exit_error(3);
	while (*str)
	{
		if (!(split[index] = ft_strnew(21)))
			ft_exit_error(3);
		split[index][20] = '\0';
		ft_strncpy(split[index], str, chr);
		index++;
		str = str + chr;
		str++;
	}
	return (split);
}
