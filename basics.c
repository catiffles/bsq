/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 15:58:38 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/01 15:58:40 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putmatrix(char **str, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < row)
	{
		while (j < col)
		{
			ft_putchar(str[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}
