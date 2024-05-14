/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:44:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 15:58:38 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_camera(t_camera *camera)
{
	if (camera->x < INT_MIN || camera->y < INT_MIN || camera->z < INT_MIN
		|| camera->xv < -1 || camera->yv < -1 || camera->zv < -1
		|| camera->fov < 0)
		return (false);
	return (true);
}

void	parse_camera(t_minirt *data, t_list **input_lst)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		printf("Error: allocation failed\n");
	camera->name = (*input_lst)->content;
	camera->x = check_coordinate(get_nth_content(*input_lst, 1));
	camera->y = check_coordinate(get_nth_content(*input_lst, 2));
	camera->z = check_coordinate(get_nth_content(*input_lst, 3));
	camera->xv = check_vec3(get_nth_content(*input_lst, 4));
	camera->yv = check_vec3(get_nth_content(*input_lst, 5));
	camera->zv = check_vec3(get_nth_content(*input_lst, 6));
	camera->fov = check_fov(get_nth_content(*input_lst, 7));
	if (!validate_camera(camera))
		return (pars_error(CAMERA_ERR));
	ft_lstadd_back(&(data->objects), ft_lstnew(camera));
	move_to_nth_node(input_lst, 7);
	printf("Camera OK\n");
}
