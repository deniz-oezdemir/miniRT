/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:44:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/21 09:34:07 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static bool	validate_camera(t_camera *camera)
{
	if (camera->center.x < INT_MIN || camera->center.y < INT_MIN
		|| camera->center.z < INT_MIN || camera->dir.x < -1
		|| camera->dir.y < -1 || camera->dir.z < -1 || camera->fov < 0)
		return (false);
	return (true);
}

static t_camera	*new_camera(t_minirt *data)
{
	t_camera	*camera;

	camera = gc_get(data, 1, sizeof(t_camera));
	if (!camera)
		printf("Error: allocation failed\n");
	camera->name = CAMERA;
	camera->center.w = 1;
	camera->dir.w = 0;
	camera->transform = identity_mtx(data, 4);
	camera->inverse = invert_mtx(data, camera->transform);
	return (camera);
}

static void	set_camera_transform(t_minirt *data, t_camera *camera)
{
	camera->transform = transform_view(data, camera->center, point(0, 1, 0),
			camera->dir);
	camera->inverse = invert_mtx(data, camera->transform);
}

void	parse_camera(t_minirt *data, t_list **input_lst)
{
	t_camera	*camera;

	camera = new_camera(data);
	camera->center.x = check_coordinate(get_nth_content(*input_lst, 1));
	camera->center.y = check_coordinate(get_nth_content(*input_lst, 2));
	camera->center.z = check_coordinate(get_nth_content(*input_lst, 3));
	camera->dir.x = check_vec3(get_nth_content(*input_lst, 4));
	camera->dir.y = check_vec3(get_nth_content(*input_lst, 5));
	camera->dir.z = check_vec3(get_nth_content(*input_lst, 6));
	camera->fov = check_fov(get_nth_content(*input_lst, 7));
	if (!validate_camera(camera))
		return (pars_error(data, CAMERA_ERR));
	set_camera_transform(data, camera);
	init_camera_view(camera);
	data->world->camera = camera;
	move_to_nth_node(input_lst, 7);
	printf("Camera OK\n");
}
