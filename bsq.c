/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bcols: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 11:37:08 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/01 11:37:13 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

char **readstdin(int *rows, int *cols)
{
	t_list	*shapelist;
	char	*shape;
	char 	**astr;

	shapelist = ft_input();
	if (!shapelist)
		return (0);
	shape = ft_listconvert(shapelist);
	if (!shape)
		return (0);
	astr = ft_astr(shape, rows, cols,ft_list_size(shapelist));
	ft_list_clear(&shapelist);
	free(shape);
	return(astr);
}

t_bool validatemap(char **astr, int cols)
{
	if(error_check(astr) && validatemap(astr, cols))
		return (TRUE);
	return(FALSE);
}

int	main(int argc, char **argv)
{
	int		rows;
	int		cols;
	int 	*ptrows;
	int 	*ptcols;
	char 	**astr;
	int 	i;
	char 	**newmap;
	t_point	max;

	astr = NULL;
	rows = 0;
	cols = 0;
	i = 1;
	if (argc == 1)
	{
		ptrows = &rows;
		ptcols = &cols;
		astr = readstdin(ptrows, ptcols);
	}
	else
	{
	while (i < argc)
		{
			rows = countrows(argv[i]);
			cols = countcols(argv[i]);
			astr = readargv(argv[i]);
			if(!astr)
			{
				ft_putstr("map error");
				return (0);
			}
			ft_putmatrix(astr, rows, cols);
			i++;
		}
	}
	ft_putchar('\n');
	max = *find_biggest_square(astr, rows, cols);
	newmap = set_map_parameters(astr, rows, cols);
	ft_putmatrix(final_map(newmap, &max), rows, cols);
	//free_map(astr);
	return (0);
}
