/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:46:45 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/15 11:07:41 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3 r;

	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	return (r);
}

void test_vec_ops()
{
	t_vec3 a = {1.0, 2.0, 3.0};
	t_vec3 b = {-4.0, 999.0, 0.567321};
	print_vec3(a, "b");
	print_vec3(b, "a");
    print_vec3(vec_add(a, b), "a + b");
}

void print_vec3(t_vec3 v, char* label)
{
	int precision = 8;
	printf("%s:	(%.*f,	%.*f,	%.*f)\n", label, precision, v.x, precision, v.y, precision, v.z);
}
