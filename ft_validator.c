/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:47:42 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/14 16:47:44 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_val_lastline(const char *map)
{
	const char	*last;
	const char	*chr;

	while (*map)
		map++;
	last = map;
	chr = map;
	last -= 1;
	chr -= 2;
	if ((*chr == '.' || *chr == '#') && *last == '\n' && *map == '\0')
		return (1);
	else
		return (0);
}

static char		*ft_val_checkline(char *map)
{
	int			chr;

	chr = 1;
	while (*map != '\n' && *map != '\0')
	{
		if (*map != '.' && *map != '#')
			ft_exit_error(5);
		chr++;
		map++;
	}
	if (chr < 5 || chr > 5)
		ft_exit_error(4);
	return (map);
}

int				ft_validator(const char *map)
{
	int			tetriminos;
	int			lines;

	tetriminos = 0;
	if (!ft_val_lastline(map))
		ft_exit_error(8);
	while (*map)
	{
		lines = 1;
		while (lines++ <= 4)
		{
			map = ft_val_checkline((char*)map);
			map++;
		}
		if (*map == '\n' || *map == '\0')
		{
			tetriminos++;
			map++;
		}
		else
			ft_exit_error(6);
	}
	if (tetriminos > 26 || tetriminos == 0)
		ft_exit_error(7);
	return (tetriminos);
}
