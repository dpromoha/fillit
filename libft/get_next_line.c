/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dariadasha <dariadasha@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:53:18 by dpromoha          #+#    #+#             */
/*   Updated: 2019/01/26 22:17:16 by dariadasha       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_emp(t_listok **add, int fd, t_listok **lst)
{
	t_listok	*copy;

	if ((*add) == NULL)
	{
		copy = (t_listok*)malloc(sizeof(t_listok));
		copy->content = ft_strdup("");
		copy->fd = fd;
		copy->next = NULL;
		if ((*lst) != NULL)
		{
			copy->next = (*lst);
			(*lst) = copy;
		}
		else
			(*lst) = copy;
		(*add) = copy;
	}
}

char	*ft_read(t_listok *add, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*copy;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		copy = add->content;
		add->content = ft_strjoin(add->content, buf);
		free(copy);
		if (ft_strchr(add->content, '\n'))
			break ;
		copy = NULL;
	}
	if (ret == 0)
		return (0);
	return (add->content);
}

int		ft_line_size(char *length)
{
	int i;

	i = 0;
	if (!length[i])
		return (-1);
	while (length[i] && length[i] != '\n')
		i++;
	return (i);
}

void	ft_check_spaces(int length, t_listok **add)
{
	char *copy;

	if (length == 0)
	{
		copy = (*add)->content;
		if (ft_strchr((*add)->content, '\n') == 0)
			(*add)->content = ft_strdup("");
		else
			(*add)->content = ft_strdup(ft_strchr((*add)->content, '\n') + 1);
		free(copy);
		copy = NULL;
	}
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_listok	*lst = NULL;
	t_listok		*add;
	int				length;

	if (BUFF_SIZE < 1 || fd < 0 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	add = lst;
	while (add && add->fd != fd)
		add = add->next;
	ft_check_emp(&add, fd, &lst);
	ft_read(add, fd);
	length = ft_strlen(add->content) == 0 ? 1 : 0;
	if (length == 1)
		return (0);
	*line = ft_strsub(add->content, 0, ft_line_size(add->content));
	ft_check_spaces(length, &add);
	return (1);
}
