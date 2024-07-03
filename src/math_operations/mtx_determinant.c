/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_determinant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:31:11 by tiacovel          #+#    #+#             */
/*   Updated: 2024/07/03 17:13:25 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* Calculate the determinant of a 2x2 matrix */
double	determinant_2x2(t_mtx m)
{
	double	det;

	if (m.dim != 2)
		return (INT_MIN);
	det = m.mtx[0][0] * m.mtx[1][1] - (m.mtx[1][0] * m.mtx[0][1]);
	return (det);
}

/* Extrapolate the sub-matrix of a generic matrix by */
/* deleting the x_row and x_col from the given matrix. */
t_mtx	sub_mtx(t_minirt *data, t_mtx m, int x_row, int x_col)
{
	double	sub_m[MTX_DIM][MTX_DIM];
	int		row;
	int		col;

	row = -1;
	if (m.dim == 0)
		return (identity_mtx(data, m.dim - 1));
	while (++row < m.dim - 1)
	{
		col = -1;
		while (++col < m.dim - 1)
			sub_m[row][col] = m.mtx \
				[row + (row >= x_row)][col + (col >= x_col)];
	}
	return (create_mtx(data, (const double *)sub_m, m.dim - 1));
}

/* Calculate the determinant of the given submatrix. */
double	mtx_minor(t_minirt *data, t_mtx m, int x_row, int x_col)
{
	t_mtx	sub;
	double	det;

	sub = sub_mtx(data, m, x_row, x_col);
	det = mtx_determinant(data, sub);
	return (det);
}

/* Calculate the cofactor of a matrix. The cofactor of this */
/* function is equal to the determinant of a the sub-matrix */
/* obtained by deleting the x_row and x_col from the given matrix */
double	mtx_cofactor(t_minirt *data, t_mtx m, int row, int col)
{
	double	cofactor;

	cofactor = mtx_minor(data, m, row, col);
	if ((row + col) % 2 != 0)
		cofactor *= -1;
	return (cofactor);
}

/* Calculate the determinat of the matrix recursively with the */
/* cofactors expansion method. */
double	mtx_determinant(t_minirt *data, t_mtx m)
{
	int		col;
	double	det;

	if (m.dim == 2)
		return (determinant_2x2(m));
	det = 0;
	col = -1;
	while (++col < m.dim)
		det += mtx_cofactor(data, m, 0, col) * m.mtx[0][col];
	return (det);
}
