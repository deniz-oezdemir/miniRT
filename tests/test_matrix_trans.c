/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_trans.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:30:58 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/21 16:33:21 by tiacovel         ###   ########.fr       */
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
	printf("\nTBD Multiplying by the inverse of a translation matrix (p. 45): @Tiziano inverse needed\n");
	printf("\nMultiplying vector (-3, 4, 5) by translation (5, -3, 2):\n");
	t_vec3 v = {-3, 4, 5, 0};
	print_vec3(mult_pnt_mtx(v, translation_mtx(5, -3, 2)), "(-3, 4, 5, 0) expected");

	printf("\n\nRotating point (0, 1, 0) around the x axis:\n");
	p = (t_vec3){0, 1, 0, 1};
	print_vec3(mult_pnt_mtx(p, rot_x(PI/4)), "Half a quarter: (0, √2/2, √2/2, 1) expected");
	print_vec3(mult_pnt_mtx(p, rot_x(PI/2)), "Full quarter: (0, 0, 1, 1) expected");
	printf("\nTBD inverse of rotation (p. 49): @Tiziano inverse needed\n");

	printf("\n\nRotating point (0, 0, 1) around the y axis:\n");
	p = (t_vec3){0, 0, 1, 1};
	print_vec3(mult_pnt_mtx(p, rot_y(PI/4)), "Half a quarter: (√2/2, 0, √2/2, 1) expected");
	print_vec3(mult_pnt_mtx(p, rot_y(PI/2)), "Full quarter: (1, 0, 0, 1) expected");

	printf("\n\nRotating point (0, 1, 0) around the z axis:\n");
	p = (t_vec3){0, 1, 0, 1};
	print_vec3(mult_pnt_mtx(p, rot_z(PI/4)), "Half a quarter: (-√2/2, √2/2, 0, 1) expected");
	print_vec3(mult_pnt_mtx(p, rot_z(PI/2)), "Full quarter: (-1, 0, 0, 1) expected");

}