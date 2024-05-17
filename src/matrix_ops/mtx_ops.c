/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:39:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/17 16:57:30 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_mtx	mult_mtx_mtx(t_mtx a, t_mtx b)
{
	double	r[MTX_DIM][MTX_DIM];
	size_t	row;
	size_t	col;

	ft_bzero(r, sizeof(double) * MTX_SIZE);
	row = 0;
	while (row < MTX_DIM)
	{
		col = 0;
		while (col < MTX_DIM)
		{
			r[row][col] = a.mtx[row][0] * b.mtx[0][col]
				+ a.mtx[row][1] * b.mtx[1][col]
				+ a.mtx[row][2] * b.mtx[2][col]
				+ a.mtx[row][3] * b.mtx[3][col];
			col++;
		}
		row++;
	}
	return (create_mtx(r, MTX_DIM));
}

t_vec3	mult_pnt_mtx(t_vec3 p, t_mtx m)
{
	double r[MTX_DIM];
	size_t	row;

	row = 0;
	while (row < MTX_DIM)
	{
		r[row] = m.mtx[row][0] * p.x \
			+ m.mtx[row][1] * p.y \
			+ m.mtx[row][2] * p.z \
			+ m.mtx[row][3] * p.w;
		row++;
	}
	return ((t_vec3){r[0], r[1], r[2], r[3]});
}

t_mtx	transp_mtx(t_mtx m)
{
	double	r[MTX_DIM][MTX_DIM];
	size_t	row;
	size_t	col;

	ft_bzero(r, sizeof(double) * MTX_SIZE);
	row = 0;
	while(row < m.dim)
	{
		col = 0;
		while(col < m.dim)
		{
			r[col][row] = m.mtx[row][col];
			col++;
		}
		row++;
	}
	return (create_mtx(r, MTX_DIM));
}

t_mtx	create_mtx(const double m[MTX_DIM][MTX_DIM], size_t dim)
{
	t_mtx	r;

	r.dim = dim;
	ft_memmove(r.mtx, m, sizeof(double) * MTX_SIZE);
	return (r);
}

void	test_mtx()
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

	t_mtx	a = create_mtx(a_data, MTX_DIM);
	t_mtx	b = create_mtx(b_data, MTX_DIM);

	t_mtx	mult = mult_mtx_mtx(a, b);
	t_mtx	a_transp = transp_mtx(a);
	t_mtx	mult_transp = transp_mtx(mult);

	printf("\nMatrix a:\n");
	print_mtx(a);
	printf("\nMatrix b:\n");
	print_mtx(b);
	printf("\nMatrix a * matrix b:\n");
	print_mtx(mult);
	printf("\nMatrix a transposed:\n");
	print_mtx(a_transp);
	printf("\nMatrix a * matrix b transposed:\n");
	print_mtx(mult_transp);

	printf("\n\nMatrix Transformations:\n");
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



}

void	print_mtx(t_mtx mtx)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < mtx.dim)
	{
		col = 0;
		while (col < mtx.dim)
		{
			printf("%.3f ", mtx.mtx[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}
