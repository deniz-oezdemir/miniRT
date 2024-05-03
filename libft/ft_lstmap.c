/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:18:58 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/24 11:30:28 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*tmp;

	if (!lst || !f || !del)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		new_elem = ft_lstnew(tmp);
		if (!new_elem)
		{
			del(tmp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

/* create new list via application of f on each node's content: */
/* loop over existing list */
	/* create tmp via applying f on existing content */
	/* create list element with tmp as content */
	/* if creation of new element unsuccesful: free tmp and new list */
/* add new element to back of new list */
/* return new list */
