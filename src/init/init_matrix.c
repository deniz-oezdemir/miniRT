/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:50:07 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/20 17:44:56 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// TODO:: To be replaced with garbage collector
void free_mtx(t_mtx *matrix)
{
	if (matrix->mtx != NULL) {
		for (size_t i = 0; i < matrix->dim; i++) {
			free(matrix->mtx[i]);
		}
		free(matrix->mtx);
		matrix->mtx = NULL;
		matrix->dim = 0;
	}
}

static double	**allocate_matrix(t_minirt *data, size_t dim)
{
	double	**matrix;
	int		i;

	matrix = gc_get(data, 1, dim * sizeof(double *));
	if (!matrix)
		return NULL;
	i = -1;
	while (++i < dim)
	{
		matrix[i] = gc_get(data, 1, dim * sizeof(double));
		if (!matrix[i])
		{
			// Free previously allocated rows on failure - not needed with gc?
			t_mtx temp_mtx = { .mtx = matrix, .dim = i};
			free_mtx(&temp_mtx);
			return (NULL);
		}
	}
	return (matrix);
}

t_mtx	create_mtx(t_minirt *data, const double *m, size_t dim)
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
		ft_memcpy(r.mtx[i], m + i * dim, dim * sizeof(double));
	return (r);
}
