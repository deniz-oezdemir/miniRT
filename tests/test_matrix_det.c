/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrix_det.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:17:58 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/21 10:20:01 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/tests.h"

void test_determinant_2x2(void)
{
	t_mtx m;
	double m_data[2][2] = {
		{1.0, 2},
		{3, 4.0}
	};
	printf("\n--- Test Matrix determinant 2x2 ---\n");
	m = create_mtx((const double *)m_data, 2);

	double det = determinant_2x2(m);
	printf("Determinant: %f (Expected: -2.0)\n", det);
}