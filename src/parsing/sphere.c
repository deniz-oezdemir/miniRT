/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:35 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 17:12:02 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_sphere(t_sphere *sphere)
{
	if ((sphere->diameter < INT_MIN)
		|| sphere->x < INT_MIN || sphere->y < INT_MIN || sphere->z < INT_MIN
		|| (sphere->r < 0) || (sphere->g < 0) || (sphere->b < 0))
		return (false);
	return (true);
}

void	parse_sphere(t_minirt *data, t_list **input_lst)
{
	t_sphere	*sphere;

	sphere = gc_get(data, 1, sizeof(t_sphere));
	if (!sphere)
		printf("Error: allocation failed\n");
	sphere->name = (*input_lst)->content;
	sphere->x = check_coordinate(get_nth_content(*input_lst, 1));
	sphere->y = check_coordinate(get_nth_content(*input_lst, 2));
	sphere->z = check_coordinate(get_nth_content(*input_lst, 3));
	sphere->diameter = check_coordinate(get_nth_content(*input_lst, 4));
	sphere->r = check_rgb(get_nth_content(*input_lst, 5));
	sphere->g = check_rgb(get_nth_content(*input_lst, 6));
	sphere->b = check_rgb(get_nth_content(*input_lst, 7));
	if (!validate_sphere(sphere))
		return (pars_error(data, SPHERE_ERR));
	ft_lstadd_back(&(data->objects), gc_lstnew(data, sphere));
	move_to_nth_node(input_lst, 7);
	printf("Sphere OK\n");
}
