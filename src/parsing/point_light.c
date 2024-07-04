/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:08 by tiacovel          #+#    #+#             */
/*   Updated: 2024/07/04 16:18:21 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static bool	validate_light(t_pntlight *light)
{
	if ((light->intensity < 0) || light->center.x < INT_MIN
		|| light->center.y < INT_MIN || light->center.z < INT_MIN
		|| (light->color.r < 0) || (light->color.g < 0) || (light->color.b < 0))
		return (false);
	return (true);
}

void	parse_pnt_light(t_minirt *data, t_list **input_lst)
{
	t_light	*l;

	l = gc_get(data, 1, sizeof(t_light));
	if (!l)
		exit_program(data, MEM_ALC_ERR);
	l->name = PNT_LIGHT;
	l->pnt_light.center.x = check_coordinate(get_nth_content(*input_lst, 1));
	l->pnt_light.center.y = check_coordinate(get_nth_content(*input_lst, 2));
	l->pnt_light.center.z = check_coordinate(get_nth_content(*input_lst, 3));
	l->pnt_light.intensity = check_intensity(get_nth_content(*input_lst, 4));
	l->pnt_light.center.w = 1;
	l->pnt_light.color.r = check_rgb(get_nth_content(*input_lst, 5)) / 255.0;
	l->pnt_light.color.g = check_rgb(get_nth_content(*input_lst, 6)) / 255.0;
	l->pnt_light.color.b = check_rgb(get_nth_content(*input_lst, 7)) / 255.0;
	l->pnt_light.shadow = 0;
	if (!validate_light(&(l->pnt_light)))
		return (exit_program(data, LIGHT_ERR));
	l->pnt_light.light = mult_color_scalar(l->pnt_light.color,
			l->pnt_light.intensity);
	ft_lstadd_back(&(data->world->lights), gc_lstnew(data, l));
	move_to_nth_node(input_lst, 7);
	printf("Light OK\n");
}
