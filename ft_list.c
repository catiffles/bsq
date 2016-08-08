/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 14:23:31 by cdavila           #+#    #+#             */
/*   Updated: 2016/08/03 14:23:33 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_head.h"

t_list	*ft_create_elem(char data)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->c = data;
		tmp->next = NULL;
	}
	return (tmp);
}

void	ft_list_push_back(t_list **begin_list, char data)
{
	t_list	*tmp;

	if (!begin_list)
		return ;
	tmp = *begin_list;
	if (*begin_list)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*list;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	ft_list_clear(t_list **begin_list)
{
	t_list	*tmp;

	if (!begin_list)
		return ;
	if (*begin_list)
	{
		while ((*begin_list)->next)
		{
			tmp = *begin_list;
			*begin_list = (*begin_list)->next;
			free(tmp);
		}
	}
	*begin_list = NULL;
}
