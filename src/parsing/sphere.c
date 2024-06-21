/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:35 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/21 09:31:11 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static bool	validate_sphere(t_sphere *sphere)
{
	if ((sphere->diameter < INT_MIN) || sphere->center.x < INT_MIN
		|| sphere->center.y < INT_MIN || sphere->center.z < INT_MIN
		|| (sphere->color.r < 0) || (sphere->color.g < 0)
		|| (sphere->color.b < 0))
		return (false);
	return (true);
}

static t_shape	*new_sphere(t_minirt *data)
{
	t_shape	*sh;

	sh = gc_get(data, 1, sizeof(t_shape));
	if (!sh)
		printf("Error: allocation failed\n");
	sh->name = SPHERE;
	sh->sphere.center.w = 1;
	sh->transform = identity_mtx(data, 4);
	sh->inverse = identity_mtx(data, 4);
	sh->transpose = identity_mtx(data, 4);
	sh->material = default_material();
	sh->sphere.color = (t_color){0.0, 0.0, 0.0};
	return (sh);
}

static void	set_sphere_transform(t_minirt *data, t_shape *sh)
{
	t_mtx	scale;
	t_mtx	translate;
	double	radius;

	radius = sh->sphere.diameter / 2;
	scale = scaling(data, radius, radius, radius);
	translate = translation_mtx(data, sh->sphere.center.x, sh->sphere.center.y,
			sh->sphere.center.z);
	set_transform(data, sh, mult_mtx_mtx(data, translate, scale));
}

void	parse_sphere(t_minirt *data, t_list **input_lst)
{
	t_shape	*sh;

	sh = new_sphere(data);
	sh->sphere.center.x = check_coordinate(get_nth_content(*input_lst, 1));
	sh->sphere.center.y = check_coordinate(get_nth_content(*input_lst, 2));
	sh->sphere.center.z = check_coordinate(get_nth_content(*input_lst, 3));
	sh->sphere.diameter = check_coordinate(get_nth_content(*input_lst, 4));
	sh->color.r = check_rgb(get_nth_content(*input_lst, 5)) / 255.0;
	sh->color.g = check_rgb(get_nth_content(*input_lst, 6)) / 255.0;
	sh->color.b = check_rgb(get_nth_content(*input_lst, 7)) / 255.0;
	if (!validate_sphere(&(sh->sphere)))
		return (pars_error(data, SPHERE_ERR));
	set_sphere_transform(data, sh);
	ft_lstadd_back(&(data->world->objects), gc_lstnew(data, sh));
	move_to_nth_node(input_lst, 7);
	sh->sphere.center = point(0, 0, 0);
	printf("Sphere OK\n");
}
