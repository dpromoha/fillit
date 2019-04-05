/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:21:14 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 15:56:41 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*listok;

	if (!(listok = (t_list*)malloc(sizeof(*listok))))
		return (NULL);
	if (!content)
	{
		listok->content = NULL;
		listok->content_size = 0;
	}
	else
	{
		if (!(listok->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(listok->content, content, content_size);
		listok->content_size = content_size;
	}
	listok->next = NULL;
	return (listok);
}
