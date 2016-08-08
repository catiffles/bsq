/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readargv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:46:31 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/03 17:46:33 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

int		countrows(char *ar1)
{
	char	buf;
	int		fd;
	int		rows;
	int		line;

	line = 0;
	rows = 0;
	fd = open(ar1, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) != 0)
	{
		if (buf == '\n')
			line++;
		rows = line - 1;
	}
	close(fd);
	return (rows);
}

int		countcols(char *ar1)
{
	char	buf;
	int		fd;
	int		cols;
	int		count;
	int		line;

	line = 0;
	cols = 0;
	count = 0;
	fd = open(ar1, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) != 0 && line <= 2)
	{
		if (buf == '\n')
		{
			line++;
			cols = count;
			count = 0;
		}
		count++;
	}
	close(fd);
	return (cols);
}

char	**readargv(char *ar1)
{
	char	buf;
	char	**str;
	int		row;
	int		col;
	int		fd;

	row = 0;
	col = 0;
	str = (char**)malloc(sizeof(char*) * countrows(ar1));
	if (!str)
		return (0);
	fd = open(ar1, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) != 0)
	{
		str[row] = (char*)malloc(sizeof(char) * countcols(ar1));
		if (buf == '\n')
		{
			row++;
			col = 0;
		}
		if (row > 0 && buf != '\n')
		{
			str[row - 1][col - 1] = buf;
		}
		col++;
	}
	close(fd);
	return (str);
}
