/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:59:24 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/21 11:59:31 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUF_SIZE 4096

# include <stdlib.h> /* malloc free */
# include <unistd.h> /* write close read */
# include <fcntl.h> /* open */
# include <stdio.h> /* delete */

typedef struct  tetro
{
    int         p1;
    int         p2;
    int         p3;
    int         p4;
	char        letter;
}               tetrimino;

void			ft_console(char *argv);
char			*ft_readfile(char *str);
void			ft_exit_error(int i);
int				ft_validator(const char *map);
char			**ft_tetro_splitter(char *str, int size);
void            ft_smart_validator(char **split, int size);
tetrimino       **ft_tetriminos(char** split, int size);
int				*ft_newgrid(int size);
int         	ft_fillit(int i, int *grid, tetrimino **tetro, int gridsize, int size);
void            ft_putgrid(int *grid, int size);
int             *ft_grid_border(int gridsize, int s);
tetrimino 		*ft_tetro_set_value(tetrimino *tetro, int num);
int 			*ft_extend_grid(int gridsize);
int   			ft_move_forward(tetrimino *t, int gridsize);
tetrimino 		*ft_move_to_corner(tetrimino *t, int gridsize);
int   			ft_check_move(tetrimino *t, int gridsize);
int             ft_gridsize(int size);
tetrimino 		**ft_tetro_resizer(tetrimino **tetro, int gridsize);

int             ft_sqrt(int num);
void			ft_ptest(void);
char			*ft_strendline(char *str);





char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);

#endif
