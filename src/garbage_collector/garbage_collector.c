/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:50:33 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/27 16:21:55 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/*	nmemb and size of new memory space (same as for ft_calloc) */
void	*gc_get(t_minirt *data, size_t nmemb, size_t size)
{
	void	*new;

	new = ft_calloc(nmemb, size);
	if (!new)
		return (NULL);
	gc_collect(data, new);
	return (new);
}

/*	can also be used without gc_get to collect malloc'ed space */
void	gc_collect(t_minirt *data, void *new)
{
	t_list	*node;
	t_list	*tmp;
	t_list	**head;

	head = &(data->grbg);
	node = ft_calloc(1, sizeof(t_list));
	if (!node)
		exit_program(data, GC_MEM_ERR);
	node->content = new;
	node->next = NULL;
	if (!(*head))
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return ;
}

void	gc_free(t_list *grbg)
{
	t_list	*curr;
	t_list	*next;

	curr = grbg;
	while (curr)
	{
		next = curr->next;
		if (curr->content)
			free(curr->content);
		free(curr);
		curr = next;
	}
}
