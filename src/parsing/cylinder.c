/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:46:53 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 15:58:47 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_cylinder(t_cylinder *cylinder)
{
	if (cylinder->x < INT_MIN || cylinder->y < INT_MIN || cylinder->z < INT_MIN
		|| cylinder->xv < -1 || cylinder->yv < -1 || cylinder->zv < -1
		|| cylinder->diameter < INT_MIN || cylinder->height < INT_MIN
		|| (cylinder->r < 0) || (cylinder->g < 0) || (cylinder->b < 0))
		return (false);
	return (true);
}

void	parse_cylinder(t_minirt *data, t_list **input_lst)
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		printf("Error: allocation failed\n");
	cylinder->name = (*input_lst)->content;
	cylinder->x = check_coordinate(get_nth_content(*input_lst, 1));
	cylinder->y = check_coordinate(get_nth_content(*input_lst, 2));
	cylinder->z = check_coordinate(get_nth_content(*input_lst, 3));
	cylinder->xv = check_vec3(get_nth_content(*input_lst, 4));
	cylinder->yv = check_vec3(get_nth_content(*input_lst, 5));
	cylinder->zv = check_vec3(get_nth_content(*input_lst, 6));
	cylinder->diameter = check_coordinate(get_nth_content(*input_lst, 7));
	cylinder->height = check_coordinate(get_nth_content(*input_lst, 8));
	cylinder->r = check_rgb(get_nth_content(*input_lst, 9));
	cylinder->g = check_rgb(get_nth_content(*input_lst, 10));
	cylinder->b = check_rgb(get_nth_content(*input_lst, 11));
	if (!validate_cylinder(cylinder))
		return (pars_error(CYLINDER_ERR));
	ft_lstadd_back(&(data->objects), ft_lstnew(cylinder));
	move_to_nth_node(input_lst, 11);
	printf("Cylinder OK\n");
}
