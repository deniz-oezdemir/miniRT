/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:32:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/13 18:50:23 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	*get_nth_content(t_list *list, int n)
{
	int i;

	i = -1;
	while (++i < n && list != NULL)
		list = list->next;
	if (list != NULL)
		return list->content;
	else
		return NULL;
}

void	move_to_nth_node(t_list **list, int n)
{
	int	i;

	i = -1;
	while (++i < n && *list != NULL)
		*list = (*list)->next;
}
