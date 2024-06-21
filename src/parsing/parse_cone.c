/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:25:18 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:25:35 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static bool	validate_cone(t_cone *cone)
{
	if (cone->center.x < INT_MIN || cone->center.y < INT_MIN
		|| cone->center.z < INT_MIN || cone->dir.x < -1 || cone->dir.y < -1
		|| cone->dir.z < -1 || cone->diameter < INT_MIN
		|| cone->height < INT_MIN || (cone->color.r < 0) || (cone->color.g < 0)
		|| (cone->color.b < 0))
		return (false);
	return (true);
}

static t_shape	*new_cone(t_minirt *data)
{
	t_shape	*shape;

	shape = gc_get(data, 1, sizeof(t_shape));
	if (!shape)
		printf("Error: allocation failed\n");
	shape->name = CONE;
	shape->cone.center.w = 1;
	shape->cone.dir.w = 0;
	shape->cone.minimum = -INFINITY;
	shape->cone.maximum = INFINITY;
	shape->transform = identity_mtx(data, 4);
	shape->inverse = identity_mtx(data, 4);
	shape->transpose = identity_mtx(data, 4);
	shape->material = default_material();
	return (shape);
}

static void	set_cone_transform(t_minirt *data, t_shape *shape)
{
	t_mtx	scale;
	t_mtx	rotate;
	t_mtx	translate;
	double	radius;

	radius = shape->cone.diameter / 2;
	translate = translation_mtx(data, shape->cone.center.x,
			shape->cone.center.y, shape->cone.center.z);
	scale = scaling(data, radius, 1, radius);
	rotate = rotation_mtx(data, shape->cone.dir);
	set_transform(data, shape, mult_mtx_mtx(data, translate, mult_mtx_mtx(data,
				rotate, scale)));
}

void	parse_cone(t_minirt *data, t_list **input_list)
{
	t_shape	*shape;

	shape = new_cone(data);
	shape->cone.center.x = check_coordinate(get_nth_content(*input_list, 1));
	shape->cone.center.y = check_coordinate(get_nth_content(*input_list, 2));
	shape->cone.center.z = check_coordinate(get_nth_content(*input_list, 3));
	shape->cone.dir.x = check_vec3(get_nth_content(*input_list, 4));
	shape->cone.dir.y = check_vec3(get_nth_content(*input_list, 5));
	shape->cone.dir.z = check_vec3(get_nth_content(*input_list, 6));
	shape->cone.diameter = check_coordinate(get_nth_content(*input_list, 7));
	shape->cone.height = check_coordinate(get_nth_content(*input_list, 8));
	shape->cone.minimum = -shape->cone.height / 2;
	shape->cone.maximum = shape->cone.height / 2;
	shape->color.r = check_rgb(get_nth_content(*input_list, 9)) / 255.0;
	shape->color.g = check_rgb(get_nth_content(*input_list, 10)) / 255.0;
	shape->color.b = check_rgb(get_nth_content(*input_list, 11)) / 255.0;
	if (!validate_cone(&(shape->cone)))
		return (pars_error(data, CONE_ERR));
	set_cone_transform(data, shape);
	ft_lstadd_back(&(data->world->objects), gc_lstnew(data, shape));
	move_to_nth_node(input_list, 11);
	shape->cone.center = point(0, 0, 0);
	printf("Cone OK\n");
}
