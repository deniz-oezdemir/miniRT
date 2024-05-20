/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vec_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:07:54 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/20 10:30:50 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/tests.h"

void test_vec_ops()
{
	t_vec3 a = {1.0, 2.0, -3.0, 0.0};
	t_vec3 b = {-4.0, 999.0, 0.567321, 0.0};
	
	printf("\n--- Test Vector operations ---\n");

	print_vec3(a, "a");
	print_vec3(b, "b");
    print_vec3(vec_add(a, b), "a + b");
	print_vec3(vec_neg(a), "a negated");
	print_vec3(vec_neg(b), "b negated");
	printf("magnitude of a: %.8f\n", magnitude(a));
	printf("magnitude of b: %.8f\n", magnitude(b));
	t_vec3 c = {0, 0, 1};
	printf("magnitude of (0, 0, 1): %.8f\n", magnitude(c));
	printf("dot product of a, b: %.8f\n", vec_dot(a, b));
	printf("dot product of a, c: %.8f\n", vec_dot(a, c));
}
