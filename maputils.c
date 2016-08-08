/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:03:47 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/02 17:03:48 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

char	**set_map_parameters(char **astr, int rows, int cols)
{
	int		i;
	int		j;
	char	**newmap;

	newmap = (char**)malloc(sizeof(char*) * rows);
	i = 0;
	while (i < rows)
	{
		j = 0;
		newmap[i] = (char*)malloc(sizeof(char) * cols);
		while (j < cols)
		{
			newmap[i][j] = astr[i][j];
			j++;
		}
		newmap[i][j] = '\0';
		i++;
	}
	return (newmap);
}

void	free_map(char **astr)
{
	int i;

	i = 0;
	while (astr[i])
	{
		free(astr[i]);
		i++;
	}
	free(astr);
}
