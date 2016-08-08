/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 17:42:02 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/02 17:42:04 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

t_bool	error_check(char **astr)
{
	int i;
	int j;

	i = 0;
	while (astr[i])
	{
		j = 0;
		while (astr[i][j])
		{
			if (!valid_char(astr[i][j]))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

t_bool	valid_char(char c)
{
	if (c != 'o' && c != '.')
		return (FALSE);
	return (TRUE);
}

t_bool	valid_rowcol(char **astr, int cols)
{
	int i;
	int j;
	int countlines;

	i = 0;
	countlines = 0;
	while (astr[i])
	{
		j = 0;
		while (astr[i][j])
		{
			j++;
		}
		if (j == cols)
			countlines++;
		i++;
	}
	if (i == countlines)
		return(TRUE);
	return (FALSE);
}
