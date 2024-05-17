/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:18:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/15 13:26:20 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

/* create different functions for different types */
int	***init_ptr_matrix(t_minirt *data, int row, int col)
{
	int ***matrix;
	int i;

	matrix = (int ***)gc_get(data, row, sizeof(int **)); i = 0;
	while (i < row)
	{
		matrix[i] = (int **)gc_get(data, col, sizeof(int *));
		i++;
	}
	return (matrix);
}

double	**init_double_matrix(t_minirt *data, int row, int col)
{
	double **matrix;
	int i;

	matrix = (double **)gc_get(data, row, sizeof(double *));
	i = 0;
	while (i < row)
	{
		matrix[i] = (double *)gc_get(data, col, sizeof(double));
		i++;
	}
	return (matrix);
}
