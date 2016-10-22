/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 14:08:33 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/15 14:08:34 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_smart_valtetrimino(char *str)
{
	int			num;

	num = 0;
	while (*str)
	{
		if (*str == '#')
			num++;
		str++;
	}
	if (num != 4)
		ft_exit_error(9);
}

static int		ft_smart_shape_validator(int *tmp, int n)
{
//	printf("%d", tmp[0]);
//	printf("%d", tmp[1]);
//	printf("%d", tmp[2]);
//	printf("%d", tmp[3]);
//	printf("%d\n", tmp[4]);
//	printf("%d", tmp[5]);
//	printf("%d", tmp[6]);
//	printf("%d", tmp[7]);
//	printf("%d", tmp[8]);
//	printf("%d\n", tmp[9]);
//	printf("%d", tmp[10]);
//	printf("%d", tmp[11]);
//	printf("%d", tmp[12]);coordinates
//	printf("%d", tmp[13]);
//	printf("%d\n", tmp[14]);
//	printf("%d", tmp[15]);
//	printf("%d", tmp[16]);
//	printf("%d", tmp[17]);
//	printf("%d", tmp[18]);
//	printf("%d\n\n", tmp[19]);

	while (tmp[n] != 1)
		n++;
	if ((tmp[n] + tmp[n + 5] + tmp[n + 10] + tmp[n + 15] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 2] + tmp[n + 3] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 5] + tmp[n + 6] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 6] + tmp[n + 7] == 4) ||
		(tmp[n] + tmp[n + 4] + tmp[n + 5] + tmp[n + 9] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 4] + tmp[n + 5] == 4) ||
		(tmp[n] + tmp[n + 5] + tmp[n + 6] + tmp[n + 11] == 4) ||
		(tmp[n] + tmp[n + 4] + tmp[n + 5] + tmp[n + 6] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 2] + tmp[n + 6] == 4) ||
		(tmp[n] + tmp[n + 4] + tmp[n + 5] + tmp[n + 10] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 2] + tmp[n + 7] == 4) ||
		(tmp[n] + tmp[n + 5] + tmp[n + 6] + tmp[n + 7] == 4) ||
		(tmp[n] + tmp[n + 3] + tmp[n + 4] + tmp[n + 5] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 6] + tmp[n + 11] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 2] + tmp[n + 5] == 4) ||
		(tmp[n] + tmp[n + 5] + tmp[n + 10] + tmp[n + 11] == 4) ||
		(tmp[n] + tmp[n + 5] + tmp[n + 6] + tmp[n + 10] == 4) ||
		(tmp[n] + tmp[n + 1] + tmp[n + 5] + tmp[n + 10] == 4) ||
		(tmp[n] + tmp[n + 5] + tmp[n + 9] + tmp[n + 10] == 4))
		return (1);
	else
		return (-1);
}

static void		ft_smart_shaper(char **split, int size)
{
	int			index;
	int			n;
	int			*temp;

	index = 0;
	while (size > 0)
	{
		temp = (int*)malloc(sizeof(int*) * 20);
		n = -1;
		while (++n < 21)
		{
			if (split[index][n] == '#')
				temp[n] = 1;
			else
				temp[n] = 0;
		}
		if (ft_smart_shape_validator(temp, 0) == 1)
		{
			index++;
			size--;
			free(temp);
		}
		else
			ft_exit_error(10);
	}
}

void			ft_smart_validator(char **split, int size)
{
	int			sizetemp;
	int			index;

	sizetemp = size;
	index = 0;
	while (sizetemp > 0)
	{
		ft_smart_valtetrimino(split[index]);
		index++;
		sizetemp--;
	}
	ft_smart_shaper(split, size);
}
