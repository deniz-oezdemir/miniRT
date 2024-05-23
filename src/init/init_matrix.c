/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:50:07 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/23 11:56:39 by tiacovel         ###   ########.fr       */
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

static double	**allocate_matrix(size_t dim)
{
	double	**matrix;
	size_t	i;

	matrix = malloc(dim * sizeof(double *));
	if (!matrix)
		return NULL;
	i = -1;
	while (++i < dim)
	{
		matrix[i] = malloc(dim * sizeof(double));
		if (!matrix[i])
		{
			// Free previously allocated rows on failure
			t_mtx temp_mtx = { .mtx = matrix, .dim = i};
			free_mtx(&temp_mtx);
			return (NULL);
		}
	}
	return (matrix);
}

t_mtx	create_mtx(const double *m, size_t dim)
{
	t_mtx r;
	size_t	i;
	
	r.dim = dim;
	r.mtx = allocate_matrix(dim);
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
