/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:25 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/17 12:06:43 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_plane(t_plane *plane)
{
	if (plane->center.x < INT_MIN
		|| plane->center.y < INT_MIN
		|| plane->center.z < INT_MIN
		|| (plane->color.r < 0)
		|| (plane->color.g < 0)
		|| (plane->color.b < 0)
		|| plane->dir.x < -1
		|| plane->dir.y < -1
		|| plane->dir.z < -1)
		return (false);
	return (true);
}

static t_shape	*new_plane(t_minirt *data)
{
	t_shape	*sh;
	//
	sh = gc_get(data, 1, sizeof(t_shape));
	if (!sh)
		printf("Error: allocation failed\n");
	sh->name = PLANE;
	sh->plane.center.w = 1;
	sh->plane.dir.w = 0;
	sh->transform = identity_mtx(data, 4);
	sh->inverse = identity_mtx(data, 4);
	sh->transpose = identity_mtx(data, 4);
	sh->material = default_material();
	sh->sphere.color = (t_color){0.0, 0.0, 0.0};
	return (sh);
}

static void	set_plane_transform(t_minirt *data, t_shape *sh)
{
	t_mtx	rotate;
	t_mtx	translate;

	translate = translation_mtx(data, sh->plane.center.x,
		sh->plane.center.y,
		sh->plane.center.z);
	rotate = rotation_mtx(data, sh->plane.dir);
	set_transform(data, sh, mult_mtx_mtx(data, translate, rotate));
}

void	parse_plane(t_minirt *data, t_list **input_lst)
{
	t_shape	*sh;

	sh = new_plane(data);
	sh->plane.center.x = check_coordinate(get_nth_content(*input_lst, 1));
	sh->plane.center.y = check_coordinate(get_nth_content(*input_lst, 2));
	sh->plane.center.z = check_coordinate(get_nth_content(*input_lst, 3));
	sh->plane.dir.x = check_vec3(get_nth_content(*input_lst, 4));
	sh->plane.dir.y = check_vec3(get_nth_content(*input_lst, 5));
	sh->plane.dir.z = check_vec3(get_nth_content(*input_lst, 6));
	sh->color.r = check_rgb(get_nth_content(*input_lst, 7)) / 255.0;
	sh->color.g = check_rgb(get_nth_content(*input_lst, 8)) / 255.0;
	sh->color.b = check_rgb(get_nth_content(*input_lst, 9)) / 255.0;
	if (!validate_plane(&(sh->plane)))
		return (pars_error(data, PLANE_ERR));
	set_plane_transform(data, sh);
	ft_lstadd_back(&(data->world->objects), gc_lstnew(data, sh));
	move_to_nth_node(input_lst, 9);
	printf("Plane OK\n");
}
