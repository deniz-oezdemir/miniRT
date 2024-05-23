/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:20:13 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/23 15:39:06 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/tests.h"

void	test_mtx_ops(void)
{
	double a_data[MTX_DIM][MTX_DIM] = {
		{1.56, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 69.4242},
		{5, 4, 3, 2}
	};
	double b_data[MTX_DIM][MTX_DIM] = {
		{-2, 1, 2, 3},
		{3, 2, 1, -1},
		{4, 3, 6, 5},
		{1, 2, 7, 8}
	};
	double c_data[MTX_DIM][MTX_DIM] = {
		{-5, 2, 6, -8},
		{1, -5, 1, 8},
		{7, 7, -6, -7},
		{1, -3, 7, 4}
	};
	double d_data[MTX_DIM][MTX_DIM] = {
		{8, -5, 9, 2},
		{7, 5, 6, 1},
		{-6, 0, 9, 6},
		{-3, 0, -9, -4}
	};

	printf("\n--- Test Matrix operations ---\n");

	t_mtx	a = create_mtx((const double *)a_data, MTX_DIM);
	t_mtx	b = create_mtx((const double *)b_data, MTX_DIM);
	t_mtx	c = create_mtx((const double *)c_data, MTX_DIM);
	t_mtx	d = create_mtx((const double *)d_data, MTX_DIM);

	t_mtx	mult = mult_mtx_mtx(a, b);
	t_mtx	a_transp = transp_mtx(a);
	t_mtx	mult_transp = transp_mtx(mult);
	t_mtx	inv_mtx = invert_mtx(c);
	t_mtx	inv_mtx2 = invert_mtx(d);

	printf("\nMatrix a:\n");
	print_mtx(a);
	printf("\nMatrix b:\n");
	print_mtx(b);
	printf("\nMatrix c:\n");
	print_mtx(c);
	printf("\nMatrix a * matrix b:\n");
	print_mtx(mult);
	printf("\nMatrix a transposed:\n");
	print_mtx(a_transp);
	printf("\nMatrix a * matrix b transposed:\n");
	print_mtx(mult_transp);
	printf("\nMatrix c inverted:\n");
	print_mtx(inv_mtx);
	printf("\nMatrix d inverted:\n");
	print_mtx(inv_mtx2);

// 	printf("\n\nMatrix Transformations:\n");
// 	printf("\nTranslation-Matrix of 34.56, 1243, 0.976796:\n");
// 	print_mtx(translation_mtx(34.56, 1243, 0.976796));
// 	printf("\nMultiplying point (-3, 4, 5) by translation (5, -3, 2):\n");
// 	t_vec3 p = {-3, 4, 5, 1};
// 	print_vec3(mult_pnt_mtx(p, translation_mtx(5, -3, 2)), "(2, 1, 7, 1) expected");
// 	printf("\nTBD Multiplying by the inverse of a translation matrix (p. 45): @Tiziano inverse needed\n");
// 	printf("\nMultiplying vector (-3, 4, 5) by translation (5, -3, 2):\n");
// 	t_vec3 v = {-3, 4, 5, 0};
// 	print_vec3(mult_pnt_mtx(v, translation_mtx(5, -3, 2)), "(-3, 4, 5, 0) expected");

// 	printf("\n\nRotating point (0, 1, 0) around the x axis:\n");
// 	p = (t_vec3){0, 1, 0, 1};
// 	print_vec3(mult_pnt_mtx(p, rot_x(PI/4)), "Half a quarter: (0, √2/2, √2/2, 1) expected");
// 	print_vec3(mult_pnt_mtx(p, rot_x(PI/2)), "Full quarter: (0, 0, 1, 1) expected");
// 	printf("\nTBD inverse of rotation (p. 49): @Tiziano inverse needed\n");

// printf("\n\nRotating point (0, 0, 1) around the y axis:\n");
// 	p = (t_vec3){0, 0, 1, 1};
// 	print_vec3(mult_pnt_mtx(p, rot_y(PI/4)), "Half a quarter: (√2/2, 0, √2/2, 1) expected");
// 	print_vec3(mult_pnt_mtx(p, rot_y(PI/2)), "Full quarter: (1, 0, 0, 1) expected");

// printf("\n\nRotating point (0, 1, 0) around the z axis:\n");
// 	p = (t_vec3){0, 1, 0, 1};
// 	print_vec3(mult_pnt_mtx(p, rot_z(PI/4)), "Half a quarter: (-√2/2, √2/2, 0, 1) expected");
// 	print_vec3(mult_pnt_mtx(p, rot_z(PI/2)), "Full quarter: (-1, 0, 0, 1) expected");

printf("\n\nA scaling matrix (2, 3, 4) applied to a point (-4, 6, 8):\n");
	p = (t_vec3){-4, 6, 8, 1};
	print_vec3(mult_pnt_mtx(p, scaling(2, 3, 4)), "(-8, 18, 32) expected");

printf("\n\nA scaling matrix (2, 3, 4) applied to a vector (-4, 6, 8):\n");
	p = (t_vec3){-4, 6, 8, 0};
	print_vec3(mult_pnt_mtx(p, scaling(2, 3, 4)), "(-8, 18, 32) expected");

printf("\nTBD Multiplying by the inverse of a scaling matrix (p. 46): @Tiziano inverse needed\n");


printf("\n\nReflection is scaling by a negativ value (-1, 1, 1) applied to a point (2, 3, 4):\n");
	p = (t_vec3){2, 3, 4, 1};
	print_vec3(mult_pnt_mtx(p, scaling(-1, 1, 1)), "(-2, 3, 4) expected");
}
