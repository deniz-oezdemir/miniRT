/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:46:53 by tiacovel          #+#    #+#             */
/*   Updated: 2024/07/01 17:24:34 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static bool	validate_cylinder(t_cylinder *cylinder)
{
	if (cylinder->center.x < INT_MIN || cylinder->center.y < INT_MIN
		|| cylinder->center.z < INT_MIN || cylinder->dir.x < -1
		|| cylinder->dir.y < -1 || cylinder->dir.z < -1
		|| cylinder->diameter < INT_MIN || cylinder->height < INT_MIN
		|| (cylinder->color.r < 0) || (cylinder->color.g < 0)
		|| (cylinder->color.b < 0))
		return (false);
	return (true);
}

static t_shape	*new_cylinder(t_minirt *data)
{
	t_shape	*sh;

	sh = gc_get(data, 1, sizeof(t_shape));
	if (!sh)
		exit_program(data, MEM_ALC_ERR);
	sh->name = CYLINDER;
	sh->cylinder.center.w = 1;
	sh->cylinder.dir.w = 0;
	sh->cylinder.minimum = -INFINITY;
	sh->cylinder.maximum = INFINITY;
	sh->transform = identity_mtx(data, 4);
	sh->inverse = identity_mtx(data, 4);
	sh->transpose = identity_mtx(data, 4);
	sh->material = default_material();
	return (sh);
}

static void	set_cylinder_transform(t_minirt *data, t_shape *sh)
{
	t_mtx	scale;
	t_mtx	rotate;
	t_mtx	translate;
	double	radius;

	radius = sh->cylinder.diameter / 2;
	translate = translation_mtx(data, sh->cylinder.center.x,
			sh->cylinder.center.y, sh->cylinder.center.z);
	scale = scaling(data, radius, 1, radius);
	rotate = rotation_mtx(data, sh->cylinder.dir);
	set_transform(data, sh, mult_mtx_mtx(data, translate, mult_mtx_mtx(data,
				rotate, scale)));
}

void	parse_cylinder(t_minirt *data, t_list **input_lst)
{
	t_shape	*sh;

	sh = new_cylinder(data);
	sh->cylinder.center.x = check_coordinate(get_nth_content(*input_lst, 1));
	sh->cylinder.center.y = check_coordinate(get_nth_content(*input_lst, 2));
	sh->cylinder.center.z = check_coordinate(get_nth_content(*input_lst, 3));
	sh->cylinder.dir.x = check_vec3(get_nth_content(*input_lst, 4));
	sh->cylinder.dir.y = check_vec3(get_nth_content(*input_lst, 5));
	sh->cylinder.dir.z = check_vec3(get_nth_content(*input_lst, 6));
	sh->cylinder.diameter = check_coordinate(get_nth_content(*input_lst, 7));
	sh->cylinder.height = check_coordinate(get_nth_content(*input_lst, 8));
	sh->cylinder.minimum = -sh->cylinder.height / 2;
	sh->cylinder.maximum = sh->cylinder.height / 2;
	sh->color.r = check_rgb(get_nth_content(*input_lst, 9)) / 255.0;
	sh->color.g = check_rgb(get_nth_content(*input_lst, 10)) / 255.0;
	sh->color.b = check_rgb(get_nth_content(*input_lst, 11)) / 255.0;
	if (!validate_cylinder(&(sh->cylinder)))
		return (exit_program(data, CYLINDER_ERR));
	set_cylinder_transform(data, sh);
	ft_lstadd_back(&(data->world->objects), gc_lstnew(data, sh));
	move_to_nth_node(input_lst, 11);
	sh->cylinder.center = point(0, 0, 0);
	printf("Cylinder OK\n");
}
