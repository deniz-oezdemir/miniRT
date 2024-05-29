/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:23 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/29 10:52:59 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests.h"
# include "../include/minirt.h"

int main(void)
{
	t_minirt	*data;

	data = init_mlx();
	parse(data, "scene_first_sphere.rt");
	// print_scene_objects(data->world);
	
	// test_is_digit();
	// test_is_identifier();
	// test_is_in_range();
	// test_vec_ops();
	// test_determinant_2x2();
	// test_sub_mtx();
	// test_mtx_minor();
	// test_mtx_cofactor();
	// test_mtx_determinant();
	// test_mtx_determinant_4x4();
	// test_mtx_ops();
	// test_mtx_trans();
	// test_rays();
	test_inter(data);
	return (0);
}
