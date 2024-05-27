/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:36:01 by yait-nas          #+#    #+#             */
/*   Updated: 2023/12/25 22:08:33 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstlast(t_list *list);
int		found_newline(t_list *list);
void	add_up(t_list **list, char *buf);
void	creat_list(t_list **list, int fd);
int		len_to_newline(t_list *list);
void	ft_strcpy(t_list *list, char *buf);
char	*get_line_y(t_list *list);
void	free_check(t_list **list, t_list *clean_node, char *buf);
void	clean_up(t_list **list);
char	*get_next_line(int fd);

#endif
