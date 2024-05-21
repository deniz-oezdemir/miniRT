/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ops2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:31:11 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/21 10:21:16 by tiacovel         ###   ########.fr       */
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
t_mtx	sub_mtx(t_mtx m, int x_row, int x_col)
{
	double	r[m.dim - 1][m.dim - 1];
	size_t	row;
	size_t	col;
	size_t	new_row;
	size_t	new_col;

	ft_bzero(r, sizeof(double) * ((m.dim - 1)*(m.dim - 1)));
	new_row = 0;
	row = -1;
	while (++row < m.dim)
	{
		col = -1;
		new_col = 0;
		if (row == x_row)
			row++;
		while (++col < m.dim)
		{
			if (col == x_col)
				col++;
			r[new_row][new_col] = m.mtx[row][col];
			new_col++;
		}
		new_row++;
	}
	return(create_mtx((const double *)r, m.dim - 1));
}

/* Calculate the determinant of the given submatrix. */
/* It works with 3x3 matrixes. */
double	mtx_minor(t_mtx m, int x_row, int x_col)
{
	t_mtx	sub;

	if (m.dim != 3)
		return (INT_MIN);
	sub = sub_mtx(m, x_row, x_col);
	return (determinant_2x2(sub));
}

/* Calculate the cofactor of a matrix 3x3. The cofactor of this */
/* function is equal to the determinant of a the sub-matrix */
/* obtained by deleting the x_row and x_col from the given matrix */
double	mtx_cofactor(t_mtx m, int row, int col)
{
	double	cofactor;

	if (m.dim != 3)
		return (INT_MIN);
	cofactor = mtx_minor(m, row, col);
	if ((row + col) % 2 != 0)
		cofactor *= -1;
	return (cofactor);
}

/* Calculate the determinat of the matrix recursively with the */
/* cofactors expansion method. */
double	mtx_determinant(t_mtx m)
{
	size_t	col;
	double	det;
	int		sign;

	if (m.dim == 2)
		return (determinant_2x2(m));
	sign = 1;
	det = 0;
	col = -1;
	while (++col < m.dim)
	{
		if ((col % 2) != 0)
			sign = -1;
		det+= mtx_cofactor(m, 0, col) * m.mtx[0][col];
	}
	return (det);
}
