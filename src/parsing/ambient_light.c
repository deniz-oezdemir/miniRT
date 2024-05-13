/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:53 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/13 14:50:11 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_amblight(t_amblight *amblight)
{
	if ((amblight->intensity < 0)
		|| (amblight->r < 0) || (amblight->g < 0) || (amblight->b < 0))
		return false;
	return true;
}

void	parse_ambient_light(t_minirt *data, t_list **al)
{
	t_amblight *amblight;

	amblight = ft_calloc(1, sizeof(t_amblight));
	if (!amblight)
		printf("Error: allocation failed\n");
	amblight->name = (*al)->content;
	amblight->intensity = check_intensity((*al)->next->content);
	amblight->r = check_rgb((*al)->next->next->content);
	amblight->g = check_rgb((*al)->next->next->next->content);
	amblight->b = check_rgb((*al)->next->next->next->next->content);
	if (!validate_amblight(amblight))
		return ; // TODO: print an error and clean everything
	ft_lstadd_back(&(data->objects), ft_lstnew(amblight));
	(*al) = (*al)->next->next->next->next;
	printf("Ambient light OK\n");
}
