/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 20:16:22 by sutran            #+#    #+#             */
/*   Updated: 2016/08/03 20:31:55 by sutran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

char	**final_map(char **newmap, t_point *max)
{
	int	max_square;
	int	x;
	int	y;
	int	i;
	int	j;

	max_square = max->x;
	x = max->y;
	y = max->z;
	i = 0;
	while (i++ < max_square)
	{
		j = 0;
		while (j++ < max_square)
		{
			newmap[x - 1][y - 1] = 'x';
			y--;
		}
		y = max->z;
		x--;
	}
	return (newmap);
}
