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

/* # include <string.h> */
/* # include <sys/types.h> read */
/* # include <sys/uio.h> read */
/*
typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
*/

typedef struct  tetro
{
    int         p1;
    int         p2;
    int         p3;
    int         p4;
	char        letter;
}               tetrimino;


/*
** fillit
** -----------------------------------------------------------------------------
*/
void			ft_console(char *argv);
char			*ft_readfile(char *str);
void			ft_exit_error(int i);
int				ft_validator(const char *map);
char			**ft_tetro_splitter(char *str, int size);
void            ft_smart_validator(char **split, int size);

tetrimino       **ft_tetriminos(char** split, int size);
int				*ft_newgrid(int size);
int         	ft_fillit(int i, int *grid, tetrimino **tetro, int gridsize);
void            ft_putgrid(int *grid, int size);
int             *ft_grid_border(int gridsize, int s);
tetrimino 		*ft_tetro_set_value(tetrimino *tetro, int num);
int 			*ft_extend_grid(int *grid, int gridsize);
int   			ft_move_forward(tetrimino *t, int gridsize);
tetrimino 		*ft_move_to_corner(tetrimino *t, int gridsize);
int   			ft_check_move(tetrimino *t, int gridsize);
int             ft_gridsize(int size);

int             ft_sqrt(int num);
void			ft_ptest(void);
char			*ft_strendline(char *str);

// void			ft_putnstr(const char *str, int n);
/*
** STRING
** -----------------------------------------------------------------------------
*/


// size_t			ft_strlen(const char *s);
// char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
// char			*ft_strcat(char *s1, const char *s2);
// char			*ft_strncat(char *s1, const char *s2, size_t n);
// char			*ft_strchr(const char *s, int c);
// char			*ft_strrchr(const char *s, int c);
// char			*ft_strstr(const char *big, const char *little);
// int				ft_strcmp(const char *s1, const char *s2);
// int				ft_strncmp(const char*s1, const char *s2, size_t n);
// size_t			ft_strlcat(char *dst, const char *src, size_t size);
// char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strnew(size_t size);
// void			ft_strdel(char **as);
// void			ft_strclr(char *s);
// void			ft_striter(char *s, void (*f)(char *));
// void			ft_striteri(char *s, void (*f)(unsigned int, char *));
// int				ft_strequ(char const *s1, char const *s2);
// int				ft_strnequ(char const *s1, char const *s2, size_t n);
// char			*ft_strmap(char const *s, char (*f)(char));
// char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// char			*ft_strsub(char const *s, unsigned int start, size_t len);
// char			*ft_strjoin(char const *s1, char const *s2);
// char			**ft_strsplit(char const *s, char c);

/*
** MEMORY
** -----------------------------------------------------------------------------
*/
void			ft_bzero(void *s, size_t n);
// void			*ft_memset(void *b, int c, size_t len);
// void			*ft_memcpy(void *dst, const void *src, size_t n);
// void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
// void			*ft_memmove(void *dst, const void *src, size_t len);
// void			*ft_memchr(const void *s, int c, size_t n);
// int				ft_memcmp(const void *s1, const void *s2, size_t n);
// void			*ft_memalloc(size_t size);
// void			ft_memdel(void **ap);

/*
** CHECKERS
** -----------------------------------------------------------------------------
*/
// int				ft_isalpha(int c);
// int				ft_isdigit(int c);
// int				ft_isalnum(int c);
// int				ft_isascii(int c);
// int				ft_isprint(int c);
// int				ft_isspace(int c);

/*
** CHAR
** -----------------------------------------------------------------------------
*/
// int				ft_toupper(int c);
// int				ft_tolower(int c);
// char			ft_nextchar(char c);
// char			ft_prvschar(char c);

/*
** PRINT
** -----------------------------------------------------------------------------
*/
void			ft_putchar(char c);
// void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
// void			ft_putstr_fd(char const *s, int fd);
// void			ft_putnbr(int n);
// void			ft_putnbr_fd(int n, int fd);
// void			ft_putendl(char const *s);
// void			ft_putendl_fd(char const *s, int fd);



/*
** CHAINED LISTS
** -----------------------------------------------------------------------------
*/
// t_list			*ft_lstnew(void const *content, size_t content_size);
// void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
// void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
// void			ft_lstadd(t_list **alst, t_list *new);
// void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
// t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** CONVERSION
** -----------------------------------------------------------------------------
*/
// int				ft_atoi(const char *str);
// char			*ft_itoa(int n);

/*
** EXTRA
** -----------------------------------------------------------------------------
*/
// char			*ft_skipspace_beg(char *s);
// char			*ft_skipspace_end(char *s);
// size_t			ft_ptrlen(char *beg, char *end);
// char			*ft_ptrtoend(char *s);
// char			*ft_strtrim(char const *s);
// size_t			ft_strchr_qt(char *s, char c);
// char			*ft_strchrto_end(char *s, char c);
// char			*ft_skipchr(char *s, char c);
// char			*ft_skiptochr(char *s, char c);

#endif
