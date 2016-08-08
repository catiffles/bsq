/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readstdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:53:12 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/03 17:53:14 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

t_list	*ft_input(void)
{
	int		i;
	char	buf[2];
	t_list	*list;

	list = NULL;
	i = 0;
	while (read(0, buf, 1))
	{
		buf[1] = '\0';
		ft_list_push_back(&list, buf[0]);
		i++;
	}
	return (list);
}

char	*ft_listconvert(t_list *list)
{
	int		len;
	int		i;
	char	*str;

	len = ft_list_size(list);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = list->c;
		list = list->next;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_astr(char *str, int *rows, int *cols, int size)
{
	int		i;
	int		j;
	char	**astr;

	i = 0;
	j = 0;
	astr = (char**)malloc(sizeof(char*) * size + 1);
	while (*str++)
	{
		astr[i] = (char*)malloc(sizeof(char) * size + 1);
		if (*str == '\n')
		{
			i++;
			j = 0;
		}
		if (i > 0 && *str != '\n')
			astr[i - 1][j - 1] = *str;
		j++;
	}
	*rows = i - 1;
	*cols = (size - 5) / (i - 1) - 1;
	astr[*rows][*cols] = '\0';
	return (astr);
}
