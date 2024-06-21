/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:53 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:31:41 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static bool	validate_amblight(t_amblight *amblight)
{
	if ((amblight->intensity < 0) || (amblight->color.r < 0)
		|| (amblight->color.g < 0) || (amblight->color.b < 0))
		return (false);
	return (true);
}

void	parse_ambient_light(t_minirt *data, t_list **input_lst)
{
	t_amblight	*alight;

	alight = gc_get(data, 1, sizeof(t_light));
	if (!alight)
		printf("Error: allocation failed\n");
	alight->intensity = check_intensity(get_nth_content(*input_lst, 1));
	alight->color.r = check_rgb(get_nth_content(*input_lst, 2)) / 255.0;
	alight->color.g = check_rgb(get_nth_content(*input_lst, 3)) / 255.0;
	alight->color.b = check_rgb(get_nth_content(*input_lst, 4)) / 255.0;
	if (!validate_amblight(alight))
		return (pars_error(data, AMB_LIGHT_ERR));
	alight->light = mult_color_scalar(alight->color, alight->intensity);
	data->world->ambient_light = alight;
	data->world->light_nbr++;
	move_to_nth_node(input_lst, 4);
	printf("Ambient alight OK\n");
}
