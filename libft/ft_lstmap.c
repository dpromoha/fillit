/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:20:11 by dpromoha          #+#    #+#             */
/*   Updated: 2018/12/26 15:56:34 by dpromoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*test;
	t_list	*fresh;

	test = f(lst);
	if (!(new = ft_lstnew(test->content, test->content_size)))
		return (NULL);
	fresh = new;
	lst = lst->next;
	while (lst)
	{
		test = f(lst);
		if (!(new->next = ft_lstnew(test->content, test->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (fresh);
}
