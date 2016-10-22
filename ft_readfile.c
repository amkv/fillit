/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:21:17 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/13 11:21:18 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_readfile(char *name)
{
	int		fd;
	char	buf[BUF_SIZE];
    int 	ret;
	char	*box;

	if (name == NULL)
		return (NULL);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		ft_exit_error(0);
	ret = read(fd, buf, BUF_SIZE);
//    while((ret = read(fd, buf, 1)) != '\0')
//        buf[ret] = '\0';
//			*str = buf
//    while ((ret = (read(fd, chr, 1) > 0)))
// 			
// 			*str = chr
//			str++;
	if (ret < 0)
		ft_exit_error(1);
	if (!(box = ft_strnew(ret + 1)))
		ft_exit_error(3);
	ft_strcpy(box, buf);
	close(fd);
	return (box);
}
