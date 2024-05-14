/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:50:33 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 15:07:32 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

/*	nmemb and size of new memory space (same as for ft_calloc) */
void	*gc_get(t_minirt *data, size_t nmemb, size_t size)
{
	void	*new;

	new = ft_calloc(nmemb, size);
	if (!new)
	{
		ft_putstr_fd("memory allocation error\n", 2);
		//g_exitstatus = 1; //from minishell, replace with exit/error
		return (NULL);
	}
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
	{
		ft_putstr_fd("memory allocation error\n", 2);
		//g_exitstatus = 1; //from minishell, replace with exit/error
		return ;
	}
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
	t_list	*prev;

	curr = grbg;
	while (curr)
	{
		if (curr->content)
			free(curr->content);
		prev = curr;
		if (curr->next)
			curr = curr->next;
		else
		{
			free(curr);
			return ;
		}
		free(prev);
	}
}
