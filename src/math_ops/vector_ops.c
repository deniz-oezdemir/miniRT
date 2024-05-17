/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:46:45 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/17 14:48:58 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	t_vec3 r;

	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	r.w = a.w + b.w;
	return (r);
}

t_vec3	vec_neg(t_vec3 v)
{
	t_vec3 r;

	r.x = v.x * -1;
	r.y = v.y * -1;
	r.z = v.z * -1;
	r.w = v.w * -1;
	return (r);
}

double	magnitude(t_vec3 v)
{
	double m;

	m = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2));
	return (m);
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	double r;

	r = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (r);
}

void test_vec_ops()
{
	t_vec3 a = {1.0, 2.0, -3.0, 0.0};
	t_vec3 b = {-4.0, 999.0, 0.567321, 0.0};
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

void print_vec3(t_vec3 v, char* label)
{
	int precision = 8;
	printf("%s:	(%.*f,	%.*f,	%.*f 	%d)\n", label, precision, v.x, precision, v.y, precision, v.z, v.w);
}
