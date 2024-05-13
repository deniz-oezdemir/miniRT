/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:44:34 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/13 15:05:53 by tiacovel         ###   ########.fr       */
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

void	parse_camera(t_minirt *data, t_list **scene)
{
	t_camera *camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		printf("Error: allocation failed\n");
	camera->name = (*scene)->content;
	camera->x = check_coordinate((*scene)->next->content);
	camera->y = check_coordinate((*scene)->next->next->content);
	camera->z = check_coordinate((*scene)->next->next->next->content);
	camera->xv = check_vec3((*scene)->next->next->next->next->content);
	camera->yv = check_vec3((*scene)->next->next->next->next->next->content);
	camera->zv = check_vec3((*scene)->next->next->next->next->next->next->content);
	camera->fov = check_fov((*scene)->next->next->next->next->next->next->next->content);
	if (!validate_camera(camera))
		return ; // TODO: print an error and clean everything
	ft_lstadd_back(&(data->objects), ft_lstnew(camera));
	(*scene) = (*scene)->next->next->next->next->next->next->next;
	printf("Camera light OK\n");
}
