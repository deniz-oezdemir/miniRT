/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:39:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/21 10:19:25 by tiacovel         ###   ########.fr       */
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
	return (create_mtx((const double *)r, MTX_DIM));
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
	return (create_mtx((const double *)r, MTX_DIM));
}

t_mtx	identity_mtx(size_t dim)
{
	double	r[MTX_DIM][MTX_DIM];
	int		i;

	ft_bzero(r, sizeof(double) * MTX_SIZE);
	i = -1;
	while (++i < dim)
		r[i][i] = 1.0;
	return (create_mtx((const double *)r, MTX_DIM));
}

/* t_mtx	create_mtx(const double m[MTX_DIM][MTX_DIM], size_t dim)
{
	t_mtx	r;

	r.dim = dim;
	ft_memmove(r.mtx, m, sizeof(double) * MTX_SIZE);
	return (r);
} */
