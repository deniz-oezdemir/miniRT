/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:53 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/06 15:14:55 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

void	parse_ambient_light(t_minirt *data, t_list *al)
{
	t_amblight *amblight;

	amblight = ft_calloc(1, sizeof(t_amblight));
	if (!amblight)
		printf("Error: allocation failed\n");
	amblight->name = al->content;
	amblight->intensity = atof(al->next->content);
	amblight->r = ft_atoi(al->next->next->content);
	amblight->g = ft_atoi(al->next->next->next->content);
	amblight->b = ft_atoi(al->next->next->next->next->content);
	ft_lstadd_back(&(data->objects), ft_lstnew(amblight));
}
