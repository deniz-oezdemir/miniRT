/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:16:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/20 15:24:38 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void apply_rotation(t_minirt *data, t_mtx rotation) {
    t_camera *camera = data->world->camera;
    t_vec3 new_dir = mult_pnt_mtx(camera->dir, rotation);
    camera->dir = vec_norm(new_dir);
    set_camera_transform(data, camera);
    // init_camera_view(camera);
}

void	rotate(t_minirt *data, int keysym)
{
	t_mtx	rotation;
	double	angle;

	angle = 10.0 * (PI / 180.0); // 1 degree in radians
	if (keysym == XK_q)
		rotation = rot_z(data, -angle);
	else if (keysym == XK_e)
		rotation = rot_z(data, angle);
	else if (keysym == XK_w)
		rotation = rot_x(data, -angle);
	else if (keysym == XK_s)
		rotation = rot_x(data, angle);
	else if (keysym == XK_a)
		rotation = rot_y(data, -angle);
	else if (keysym == XK_d)
		rotation = rot_y(data, angle);
	else
		return ;
	apply_rotation(data, rotation);
	render_scene(data);
}

/* void	move(t_minirt *data, int keysym)
{
	if (keysym == XK_Up)
		data->origin.y0 -= 5;
	else if (keysym == XK_Down)
		data->origin.y0 += 5;
	else if (keysym == XK_Right)
		data->origin.x0 += 5;
	else if (keysym == XK_Left)
		data->origin.x0 -= 5;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
} */

/* void	zoom(t_minirt *data, int keysym)
{
	if (keysym == XK_1)
		data->view.zoom -= 2;
	else if (keysym == XK_2)
		data->view.zoom += 2;
	if (data->view.zoom > 100)
		data->view.zoom = 100;
	else if (data->view.zoom < 2)
		data->view.zoom = 2;
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
} */
