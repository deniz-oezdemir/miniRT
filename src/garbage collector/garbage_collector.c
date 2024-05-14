/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:50:33 by denizozd          #+#    #+#             */
/*   Updated: 2024/04/25 15:48:54 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	nmemb and size of new memory space (same as for ft_calloc) */
void	*get_grbg(t_prompt *prompt, size_t nmemb, size_t size)
{
	void	*new;

	new = ft_calloc(nmemb, size);
	if (!new)
	{
		ft_putstr_fd("memory allocation error\n", 2);
		g_exitstatus = 1;
		return (NULL);
	}
	collect_grbg(prompt, new);
	return (new);
}

/*	can also be used without get_grbg to collect malloc'ed space */
void	collect_grbg(t_prompt *prompt, void *new)
{
	t_grbg	*node;
	t_grbg	*tmp;
	t_grbg	**head;

	head = &(prompt->grbg_lst);
	node = ft_calloc(1, sizeof(t_grbg));
	if (!node)
	{
		ft_putstr_fd("memory allocation error\n", 2);
		g_exitstatus = 1;
		return ;
	}
	node->ptr = new;
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

void	free_grbg(t_grbg *head)
{
	t_grbg	*curr;
	t_grbg	*prev;

	curr = head;
	while (curr)
	{
		if (curr->ptr)
			free(curr->ptr);
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
