/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:53 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/28 18:02:39 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_amblight(t_amblight *amblight)
{
	if ((amblight->intensity < 0)
		|| (amblight->color.r < 0)
		|| (amblight->color.g < 0)
		|| (amblight->color.b < 0))
		return (false);
	return (true);
}

void	parse_ambient_light(t_minirt *data, t_list **input_lst)
{
	t_light	*light;

	light = gc_get(data, 1, sizeof(t_light));
	if (!light)
		printf("Error: allocation failed\n");
	light->name = AMB_LIGHT;
	light->amb_light.intensity = check_intensity(get_nth_content(*input_lst, 1));
	light->amb_light.color.r = check_rgb(get_nth_content(*input_lst, 2));
	light->amb_light.color.g = check_rgb(get_nth_content(*input_lst, 3));
	light->amb_light.color.b = check_rgb(get_nth_content(*input_lst, 4));
	if (!validate_amblight(&(light->amb_light)))
		return (pars_error(data, AMB_LIGHT_ERR));
	ft_lstadd_back(&(data->world->lights), gc_lstnew(data, light));
	data->world->light_nbr++;
	move_to_nth_node(input_lst, 4);
	printf("Ambient light OK\n");
}
