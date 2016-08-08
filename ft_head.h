/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_head.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 11:35:23 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/01 11:35:35 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAD_H
# define FT_HEAD_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define TRUE		1
# define FALSE		0

typedef int	t_bool;

typedef	struct			s_list
{
	struct s_list		*next;
	char				c;
}						t_list;

typedef struct		s_point
{
	int x;
	int y;
	int z;
}					t_point;

t_list					*ft_create_elem(char data);
void					ft_list_push_back(t_list **begin_list, char c);
int						ft_list_size(t_list *begin_list);
void					ft_list_clear(t_list **begin_list);
t_list					*ft_input(void);
char					*ft_listconvert(t_list *list);
char					**ft_astr(char *str, int *rows, int *cols, int size);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putmatrix(char **str, int row, int col);
int		countrows(char *ar1);
int		countcols(char *ar1);
char	**readargv(char *ar1);
char	**set_map_parameters(char **astr, int rows, int cols);
void	free_map(char **astr);
t_bool	error_check(char **astr);
t_bool	valid_char(char c);
char	**createsquare(int density);
t_bool	valid_rowcol(char **astr, int cols);
t_point	*find_biggest_square(char **astr, int rows, int cols);
char	**final_map(char **newmap, t_point *max);

#endif
