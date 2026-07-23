/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:54:32 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 18:50:20 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clear_list(t_list **start, void (*del)(void *), void *content)
{
	if (del)
		del(content);
	if (!(*start))
	{
		free(*start);
		return (NULL);
	}
	ft_lstclear(start, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_start;
	t_list	*new_previous;
	t_list	*cur;
	void	*cur_content;

	if (!lst || !f)
		return (NULL);
	new_start = NULL;
	new_previous = NULL;
	while (lst)
	{
		cur_content = f(lst->content);
		cur = ft_lstnew(cur_content);
		if (!cur)
			return (ft_clear_list(&new_start, del, cur_content));
		if (!new_start)
			new_start = cur;
		else
			new_previous->next = cur;
		new_previous = cur;
		lst = lst->next;
	}
	return (new_start);
}
