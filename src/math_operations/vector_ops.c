/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:46:45 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/20 10:13:16 by tiacovel         ###   ########.fr       */
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
