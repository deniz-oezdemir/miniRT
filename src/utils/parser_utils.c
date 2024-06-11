/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:32:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/11 10:07:18 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	*get_nth_content(t_list *list, int n)
{
	int	i;

	i = -1;
	while (++i < n && list != NULL)
		list = list->next;
	if (list != NULL)
		return (list->content);
	else
		return (NULL);
}

void	move_to_nth_node(t_list **list, int n)
{
	int	i;

	i = -1;
	while (++i < n && *list != NULL)
		*list = (*list)->next;
}

void	set_transform(t_shape *shape, t_mtx transform)
{
	shape->transform = transform;
	shape->inverse = invert_mtx(transform);
	shape->transpose = transp_mtx(shape->inverse);
}
