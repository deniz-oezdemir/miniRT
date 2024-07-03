/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:50:07 by tiacovel          #+#    #+#             */
/*   Updated: 2024/07/03 17:12:15 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static double	**allocate_matrix(t_minirt *data, int dim)
{
	double	**matrix;
	int		i;

	matrix = gc_get(data, 1, dim * sizeof(double *));
	if (!matrix)
		exit_program(data, MTX_MEM_ERR);
	i = -1;
	while (++i < dim)
	{
		matrix[i] = gc_get(data, 1, dim * sizeof(double));
		if (!matrix[i])
			exit_program(data, MTX_MEM_ERR);
	}
	return (matrix);
}

t_mtx	create_mtx(t_minirt *data, const double *m, int dim)
{
	t_mtx	r;
	int		i;

	r.dim = dim;
	r.mtx = allocate_matrix(data, dim);
	if (!r.mtx)
	{
		r.dim = 0;
		return (r);
	}
	i = -1;
	while (++i < dim)
		ft_memcpy(r.mtx[i], m + i * MTX_DIM, dim * sizeof(double));
	return (r);
}
