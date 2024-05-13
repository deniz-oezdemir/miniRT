/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:53 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/13 13:24:55 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

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
	ft_lstadd_back(&(data->objects), ft_lstnew(amblight));
	(*al) = (*al)->next->next->next->next;
	printf("Ambient light OK\n");
}
