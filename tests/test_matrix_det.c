/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_det.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:17:58 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/23 12:08:48 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/tests.h"

void	test_determinant_2x2(void)
{
	t_mtx m;
	int		mtx_dim = 2;
	double m_data[2][2] = {
		{1.0, 2},
		{3, 4.0}
	};
	printf("\n--- Test Matrix determinant 2x2 ---\n");
	m = create_mtx((const double *)m_data, mtx_dim);
	double det = determinant_2x2(m);

	printf("\nSource Matrix 2x2:\n");
	print_mtx(m);
	printf("\nDeterminant: %f (Expected: -2.0)\n", det);
}

void	test_sub_mtx(void)
{
	t_mtx	m;
	t_mtx	sub;
	int		m_dim = 3;
	double	m_data[3][3] = {
		{1.0, 2, 3},
		{3, 4.0, 5},
		{6, 7, 8}
	};

	printf("\n--- Test Submatrix ---\n");
	m = create_mtx((const double *)m_data, m_dim);
	sub = sub_mtx(m, 1, 1);

	printf("\nSource Matrix 3x3:\n");
	print_mtx(m);
	printf("\nSub-matrix 1-1:\n");
	print_mtx(sub);
	printf("\nSub-matrix 3-3:\n");
	print_mtx(sub_mtx(m, 3, 3));
}

void	test_mtx_minor(void)
{
	t_mtx	m;
	int		m_dim = 3;
	double	m_data[3][3] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};

	printf("\n--- Test Minor ---\n");
	m = create_mtx((const double *)m_data, m_dim);
	double minor = mtx_minor(m, 1, 0);

	printf("\nSource Matrix 3x3:\n");
	print_mtx(m);
	printf("\nMinor: %f (Expected: 25.000000)\n", minor);
}

void	test_mtx_cofactor(void)
{
	t_mtx	m;
	int		m_dim = 3;
	double	m_data[3][3] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};

	printf("\n--- Test Cofactor ---\n");
	m = create_mtx((const double *)m_data, m_dim);
	double cof = mtx_cofactor(m, 1, 0);

	printf("\nSource Matrix 3x3:\n");
	print_mtx(m);
	printf("\nCofactor: %f (Expected: -25.000000)\n", cof);
}

void	test_mtx_determinant(void)
{
	t_mtx m;
	int m_dim = 3;
	double m_data[3][3] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};

	printf("\n--- Test Determinant 3x3 ---\n");
	m = create_mtx((const double *)m_data, m_dim);
	double det = mtx_determinant(m);

	printf("\nSource Matrix 3x3:\n");
	print_mtx(m);
	printf("\nDeterminant: %f (Expected: -296.000000)\n", det);
}

void	test_mtx_determinant_4x4(void)
{
	t_mtx m;
	int m_dim = 4;
	double m_data[4][4] = {
		{-2, -8, 3, 5},
		{-3, 1, 7, 3},
		{1, 2, -9, 6},
		{-6, 7, 7, -9}
	};

	printf("\n--- Test Determinant 4x4 ---\n");
	m = create_mtx((const double *)m_data, m_dim);
	double det = mtx_determinant(m);

	printf("\nSource Matrix 4x4:\n");
	print_mtx(m);
	printf("\nDeterminant: %f (Expected: -4071.000000)\n", det);
}