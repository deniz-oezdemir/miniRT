/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:39:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/27 17:58:45 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_mtx	mult_mtx_mtx(t_minirt *data, t_mtx a, t_mtx b)
{
	double	r[MTX_DIM][MTX_DIM];
	int		row;
	int		col;

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
	return (create_mtx(data, (const double *)r, MTX_DIM));
}

t_vec3	mult_pnt_mtx(t_vec3 p, t_mtx m)
{
	double	r[MTX_DIM];
	int		row;

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

t_mtx	transp_mtx(t_minirt *data, t_mtx m)
{
	double	r[MTX_DIM][MTX_DIM];
	int		row;
	int		col;

	ft_bzero(r, sizeof(double) * MTX_SIZE);
	row = 0;
	while (row < m.dim)
	{
		col = 0;
		while (col < m.dim)
		{
			r[col][row] = m.mtx[row][col];
			col++;
		}
		row++;
	}
	return (create_mtx(data, (const double *)r, MTX_DIM));
}

t_mtx	identity_mtx(t_minirt *data, int dim)
{
	double	r[MTX_DIM][MTX_DIM];
	int		i;

	ft_bzero(r, sizeof(double) * MTX_SIZE);
	i = -1;
	while (++i < dim)
		r[i][i] = 1.0;
	return (create_mtx(data, (const double *)r, MTX_DIM));
}

t_mtx	invert_mtx(t_minirt *data, t_mtx m)
{
	double	r[MTX_DIM][MTX_DIM];
	double	det;
	t_mtx	inv;
	int		row;
	int		col;

	det = mtx_determinant(data, m);
	if (det == 0)
	{
		inv.dim = 0;
		return (inv);
	}
	row = -1;
	while (++row < m.dim)
	{
		col = -1;
		while (++col < m.dim)
			r[col][row] = mtx_cofactor(data, m, row, col) / det;
	}
	return (create_mtx(data, (const double *)r, m.dim));
}
