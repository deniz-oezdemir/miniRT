/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:23 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/30 11:00:52 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests.h"
# include "../include/minirt.h"

int main(void)
{
	t_minirt	*data;

	data = init_mlx();
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
	test_inter_2(data);
	return (0);
}
