/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:28:38 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/15 14:44:45 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// implement row and col counting if handy - need to add NULL termination to initialize functions //currently too many function args
/* assumes that the number of columns of a and rows of b are equal */

int get_rows(double **mtx)
{
	int r = 0;
	while (mtx[r][0])
		r++;
	return (r);
}

int get_cols(double **mtx)
{
	int c = 0;
	while (mtx[0][c])
		c++;
	return (c);
}

/*
double **mtx_mult(t_minirt *data, double **a, double **b)
{
	double **r;

	r = init_double_matrix(data,);

	return (r);
}
*/

void test_mtx(t_minirt *data)
{
	double **a = init_double_matrix(data, 2, 3);
	

	double a[2][3]= {	{1.0, 2.0, 3.0},
						{4.0, 5.0, 6.0}};
	double b[3][4]= {	{1.0, 2.0, 3.0, 4.0},
						{5.0, 6.0, 7.0, 8.0},
						{9.0, 10.0, 11.0, 12.0}};

	int a_rows = get_rows(a);
	int b_cols = get_cols(b);

	printf("a_rows: %d", a_rows);
	printf("b_cols: %d", b_cols);
}
