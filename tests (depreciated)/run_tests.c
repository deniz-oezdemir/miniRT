/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:23 by tiacovel          #+#    #+#             */
/*   Updated: 2024/07/04 13:44:17 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests.h"
# include "../include/minirt.h"

int main(void)
{
	t_minirt	*data;

	data = init_minirt();
	// print_scene_objects(data->world);

	// test_is_digit();
	// test_is_identifier();
	// test_is_in_range();
	// test_vec_ops();
	test_determinant_2x2(data);
	test_sub_mtx(data);
	test_mtx_minor(data);
	test_mtx_cofactor(data);
	test_mtx_determinant(data);
	test_mtx_determinant_4x4(data);
	// test_mtx_ops();
	// test_mtx_trans();
	// test_rays();
	// test_inter(data);
	// test_inter_2(data);
	// test_transform_view(data);
	// test_light(data);
	return (0);
}
