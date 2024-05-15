/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:28:28 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/15 13:26:38 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"
# include "../include/tests.h"


void	test_init_ptr_matrix(t_minirt *data)
{
	void **matrix;

	matrix = init_ptr_matrix(data, 3,3);
	if (matrix != NULL)
		printf("passed");
}
