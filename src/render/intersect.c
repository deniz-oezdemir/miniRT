/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:38:50 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:39:05 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* wrapper function for different shapes intersection:
takes minirt struct as input */
void	intersections(t_minirt *data, t_ray ray)
{
	t_list	*shapes;
	t_shape	*shape;
	t_ray	local_ray;

	shapes = data->world->objects;
	data->min = (t_inter){NULL, (double)DBL_MAX};
	while (shapes != NULL)
	{
		shape = (t_shape *)shapes->content;
		local_ray = transform_ray(ray, shape);
		if (shape->name == SPHERE)
			inter_sphere(data, shape, local_ray);
		else if (shape->name == PLANE)
			inter_plane(data, shape, local_ray);
		else if (shape->name == CYLINDER)
			inter_cylinder(data, shape, local_ray);
		else if (shape->name == CONE)
			inter_cone(data, shape, local_ray);
		shapes = shapes->next;
	}
}
