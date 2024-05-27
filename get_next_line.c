/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:31:16 by yait-nas          #+#    #+#             */
/*   Updated: 2023/12/26 13:19:15 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "get_next_line.h"

void	creat_list(t_list **list, int fd)
{
	char	*buf;
	ssize_t	chars_readen;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		chars_readen = read(fd, buf, BUFFER_SIZE);
		if (chars_readen <= 0)
		{
			free(buf);
			return ;
		}
		buf[chars_readen] = '\0';
		add_up(list, buf);
	}
}

char	*get_line_y(t_list *list)
{
	char	*buf;
	int		len;

	if (!list)
		return (NULL);
	len = len_to_newline(list);
	buf = malloc(len + 1);
	if (!buf)
		return (buf);
	ft_strcpy(list, buf);
	return (buf);
}

void	free_check(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)-> next;
		free((*list)-> content);
		free(*list);
		*list = tmp;
	}
	if (clean_node -> content[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
		*list = NULL;
	}
}

void	clean_up(t_list **list)
{
	t_list	*clean_node;
	char	*buf;
	t_list	*last_node;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clean_node = malloc(sizeof(t_list));
	buf = malloc(BUFFER_SIZE + 1);
	if (!clean_node || !buf)
		return ;
	last_node = ft_lstlast(*list);
	while (last_node -> content[i] && last_node -> content[i] != '\n')
		i++;
	while (last_node -> content[i] && last_node -> content[++i])
		buf[j++] = last_node -> content[i];
	buf[j] = '\0';
	clean_node -> content = buf;
	clean_node -> next = NULL;
	free_check(list, clean_node, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	creat_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line_y(list);
	clean_up(&list);
	return (next_line);
}
