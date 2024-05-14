/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:08 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 16:03:43 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_light(t_light *light)
{
	if ((light->intensity < 0)
		|| light->x < INT_MIN || light->y < INT_MIN || light->z < INT_MIN
		|| (light->r < 0) || (light->g < 0) || (light->b < 0))
		return (false);
	return (true);
}

void	parse_light(t_minirt *data, t_list **input_lst)
{
	t_light	*light;

	light = gc_get(data, 1, sizeof(t_light));
	if (!light)
		printf("Error: allocation failed\n");
	light->name = (*input_lst)->content;
	light->x = check_coordinate(get_nth_content(*input_lst, 1));
	light->y = check_coordinate(get_nth_content(*input_lst, 2));
	light->z = check_coordinate(get_nth_content(*input_lst, 3));
	light->intensity = check_intensity(get_nth_content(*input_lst, 4));
	light->r = check_rgb(get_nth_content(*input_lst, 5));
	light->g = check_rgb(get_nth_content(*input_lst, 6));
	light->b = check_rgb(get_nth_content(*input_lst, 7));
	if (!validate_light(light))
		return ; // TODO: print an error and clean everything
	ft_lstadd_back(&(data->objects), gc_lstnew(data, light));
	move_to_nth_node(input_lst, 7);
	printf("Light OK\n");
}
