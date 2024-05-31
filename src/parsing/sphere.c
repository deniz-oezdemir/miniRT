/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:35 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/31 22:34:18 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_sphere(t_sphere *sphere)
{
	if ((sphere->diameter < INT_MIN)
		|| sphere->center.x < INT_MIN
		|| sphere->center.y < INT_MIN
		|| sphere->center.z < INT_MIN
		|| (sphere->color.r < 0)
		|| (sphere->color.g < 0)
		|| (sphere->color.b < 0))
		return (false);
	return (true);
}

void	parse_sphere(t_minirt *data, t_list **input_lst)
{
	t_shape	*sh;

	sh = gc_get(data, 1, sizeof(t_shape));
	if (!sh)
		printf("Error: allocation failed\n");
	sh->name = SPHERE;
	sh->sphere.center.x = check_coordinate(get_nth_content(*input_lst, 1));
	sh->sphere.center.y = check_coordinate(get_nth_content(*input_lst, 2));
	sh->sphere.center.z = check_coordinate(get_nth_content(*input_lst, 3));
	sh->sphere.center.w = 1;
	sh->sphere.diameter = check_coordinate(get_nth_content(*input_lst, 4));
	sh->sphere.color.r = check_rgb(get_nth_content(*input_lst, 5));
	sh->sphere.color.g = check_rgb(get_nth_content(*input_lst, 6));
	sh->sphere.color.b = check_rgb(get_nth_content(*input_lst, 7));
	if (!validate_sphere(&(sh->sphere)))
		return (pars_error(data, SPHERE_ERR));
	sh->material = default_material(); //lighting
	print_material(sh->material); //test;
	ft_lstadd_back(&(data->world->objects), gc_lstnew(data, sh));
	data->world->object_nbr++;
	move_to_nth_node(input_lst, 7);
	printf("Sphere OK\n");
}
