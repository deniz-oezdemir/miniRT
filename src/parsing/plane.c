/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:25 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 16:03:45 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_plane(t_plane *plane)
{
	if (plane->x < INT_MIN || plane->y < INT_MIN || plane->z < INT_MIN
		|| (plane->r < 0) || (plane->g < 0) || (plane->b < 0)
		|| plane->xv < -1 || plane->yv < -1 || plane->zv < -1)
		return (false);
	return (true);
}

void	parse_plane(t_minirt *data, t_list **input_lst)
{
	t_plane	*plane;

	plane = gc_get(data, 1, sizeof(t_plane));
	if (!plane)
		printf("Error: allocation failed\n");
	plane->name = (*input_lst)->content;
	plane->x = check_coordinate(get_nth_content(*input_lst, 1));
	plane->y = check_coordinate(get_nth_content(*input_lst, 2));
	plane->z = check_coordinate(get_nth_content(*input_lst, 3));
	plane->xv = check_vec3(get_nth_content(*input_lst, 4));
	plane->yv = check_vec3(get_nth_content(*input_lst, 5));
	plane->zv = check_vec3(get_nth_content(*input_lst, 6));
	plane->r = check_rgb(get_nth_content(*input_lst, 7));
	plane->g = check_rgb(get_nth_content(*input_lst, 8));
	plane->b = check_rgb(get_nth_content(*input_lst, 9));
	if (!validate_plane(plane))
		return ; // TODO: print an error and clean everything
	ft_lstadd_back(&(data->objects), gc_lstnew(data, plane));
	move_to_nth_node(input_lst, 9);
	printf("Plane OK\n");
}
