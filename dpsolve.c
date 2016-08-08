/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpsolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 14:20:23 by sutran            #+#    #+#             */
/*   Updated: 2016/08/03 14:20:25 by sutran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int		minimum(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int		**ft_intmatrix(int rows, int cols)
{
	int	**array;
	int	index;

	index = 0;
	array = (int**)malloc(sizeof(int*) * rows);
	while (index < rows)
	{
		array[index] = (int*)malloc(sizeof(int) * cols);
		index++;
	}
	return (array);
}

t_point	*convert_grid(int **arr, int i, int j, t_point *max)
{
	arr[i][j] = minimum(arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]) + 1;
	if (arr[i][j] > max->x)
	{
		max->x = arr[i][j];
		max->y = i;
		max->z = j;
	}
	return (max);
}

void	calculate_sides(char **astr, int **arr, int i, int j)
{
	if (astr[0][j] == '.')
		arr[0][j] = 1;
	else if (astr[i][0] == '.')
		arr[i][0] = 1;
}

t_point	*find_biggest_square(char **astr, int rows, int cols)
{
	int		i;
	int		j;
	int		**arr;
	t_point	*max;
	t_point origmax;

	i = 0;
	origmax.x = 1;
	origmax.y = 0;
	origmax.z = 0;
	max = &origmax;
	arr = ft_intmatrix(rows, cols);
	while (i < rows)
	{
		j = 0;
		while (j++ < cols)
		{
			if (astr[i][j] == 'o')
				arr[i][j] = 0;
			else if (i == 0 || j == 0)
				calculate_sides(astr, arr, i, j);
			else
				convert_grid(arr, i, j, max);
		}
		i++;
	}
	return (max);
}
