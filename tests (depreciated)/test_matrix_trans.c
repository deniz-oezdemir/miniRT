/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_trans.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:30:58 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/23 16:01:34 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/tests.h"

void	test_mtx_trans(void)
{
	printf("\n--- Test Matrix transformations ---\n");

	printf("\nTranslation-Matrix of 34.56, 1243, 0.976796:\n");
	print_mtx(translation_mtx(34.56, 1243, 0.976796));
	printf("\nMultiplying point (-3, 4, 5) by translation (5, -3, 2):\n");
	t_vec3 p = {-3, 4, 5, 1};
	print_vec3(mult_pnt_mtx(p, translation_mtx(5, -3, 2)), "(2, 1, 7, 1) expected");
	printf("\nTBD Multiplying by the inverse of a translation matrix: \n");
	print_vec3(mult_pnt_mtx(p, invert_mtx(translation_mtx(5, -3, 2))), "(-8, 7, 3, 1) expected");
	printf("\nMultiplying vector (-3, 4, 5) by translation (5, -3, 2):\n");
	t_vec3 v = {-3, 4, 5, 0};
	print_vec3(mult_pnt_mtx(v, translation_mtx(5, -3, 2)), "(-3, 4, 5, 0) expected");

	printf("\n\nRotating point (0, 1, 0) around the x axis:\n");
	p = (t_vec3){0, 1, 0, 1};
	print_vec3(mult_pnt_mtx(p, rot_x(PI/4)), "Half a quarter: (0, √2/2, √2/2, 1) expected");
	print_vec3(mult_pnt_mtx(p, rot_x(PI/2)), "Full quarter: (0, 0, 1, 1) expected");
	printf("\nInverse of rotation:\n");
	print_vec3(mult_pnt_mtx(p, invert_mtx(rot_x(PI/4))), "Half a quarter: (0, √2/2, -√2/2, 1) expected");

	printf("\n\nRotating point (0, 0, 1) around the y axis:\n");
	p = (t_vec3){0, 0, 1, 1};
	print_vec3(mult_pnt_mtx(p, rot_y(PI/4)), "Half a quarter: (√2/2, 0, √2/2, 1) expected");
	print_vec3(mult_pnt_mtx(p, rot_y(PI/2)), "Full quarter: (1, 0, 0, 1) expected");

	printf("\n\nRotating point (0, 1, 0) around the z axis:\n");
	p = (t_vec3){0, 1, 0, 1};
	print_vec3(mult_pnt_mtx(p, rot_z(PI/4)), "Half a quarter: (-√2/2, √2/2, 0, 1) expected");
	print_vec3(mult_pnt_mtx(p, rot_z(PI/2)), "Full quarter: (-1, 0, 0, 1) expected");

	printf("\n\nRotating point (0, 1, 0) around the z axis:\n");
	p = (t_vec3){0, 1, 0, 1};
	print_vec3(mult_pnt_mtx(p, rot_z(PI/4)), "Half a quarter: (-√2/2, √2/2, 0, 1) expected");
	print_vec3(mult_pnt_mtx(p, rot_z(PI/2)), "Full quarter: (-1, 0, 0, 1) expected");

printf("\n\nA scaling matrix (2, 3, 4) applied to a point (-4, 6, 8):\n");
	p = (t_vec3){-4, 6, 8, 1};
	print_vec3(mult_pnt_mtx(p, scaling(2, 3, 4)), "(-8, 18, 32) expected");

printf("\n\nA scaling matrix (2, 3, 4) applied to a vector (-4, 6, 8):\n");
	p = (t_vec3){-4, 6, 8, 0};
	print_vec3(mult_pnt_mtx(p, scaling(2, 3, 4)), "(-8, 18, 32) expected");

printf("\nMultiplying by the inverse of a scaling matrix\n");
	print_vec3(mult_pnt_mtx(p, invert_mtx(scaling(2, 3, 4))), "(-2, 2, 2) expected");

printf("\n\nReflection is scaling by a negativ value (-1, 1, 1) applied to a point (2, 3, 4):\n");
	p = (t_vec3){2, 3, 4, 1};
	print_vec3(mult_pnt_mtx(p, scaling(-1, 1, 1)), "(-2, 3, 4) expected");
}
