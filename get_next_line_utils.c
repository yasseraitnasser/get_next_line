/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:11:07 by yait-nas          #+#    #+#             */
/*   Updated: 2023/12/19 13:32:08 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

t_list	*ft_lstlast(t_list *list)
{
	if (list)
		while (list -> next)
			list = list -> next;
	return (list);
}

int	found_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list -> content[i])
		{
			if (list -> content[i] == '\n')
				return (1);
			i++;
		}
		list = list -> next;
	}
	return (0);
}

void	add_up(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	last_node = ft_lstlast(*list);
	if (!last_node)
		*list = new_node;
	else
		last_node -> next = new_node;
	new_node -> content = buf;
	new_node -> next = NULL;
}

int	len_to_newline(t_list *list)
{
	int	len;
	int	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list -> content[i])
		{
			if (list -> content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list -> next;
	}
	return (len);
}

void	ft_strcpy(t_list *list, char *buf)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list -> content[i])
		{
			if (list -> content[i] == '\n')
			{
				buf[j++] = list -> content[i];
				buf[j] = '\0';
				return ;
			}
			buf[j++] = list -> content[i++];
		}
		list = list -> next;
	}
	buf[j] = '\0';
}
