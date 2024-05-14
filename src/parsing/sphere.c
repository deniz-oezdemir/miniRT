/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:47:35 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 13:11:40 by tiacovel         ###   ########.fr       */
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

	sphere = ft_calloc(1, sizeof(t_sphere));
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
		return ; // TODO: print an error and clean everything
	ft_lstadd_back(&(data->objects), ft_lstnew(sphere));
	move_to_nth_node(input_lst, 7);
	printf("Sphere OK\n");
}
