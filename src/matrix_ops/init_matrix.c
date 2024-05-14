/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:18:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 19:07:39 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

/* create different functions for different types */
int	**init_matrix(t_minirt *data, int row, int col)
{
	int **matrix;
	int i;
	int	j;

	matrix = (int **)gc_get(data, row, sizeof(int *));
	i = 0;
	j = 0;
	while (i < row)
	{
		matrix[i] = (int *)gc_get(data, col, sizeof(int));
		while(j < col)
		{
			matrix[i][j] = *((int *)gc_get(data, 1, sizeof(int)));
			j++;
		}
		i++;
		j = 0;
	}
	return (matrix);
}
