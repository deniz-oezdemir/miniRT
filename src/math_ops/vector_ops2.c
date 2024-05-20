/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:57:19 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/20 11:31:23 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	t_vec3	r;

	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;
	r.w = a.w - b.w;	// TODO: check this
	return (r);
}

t_vec3	vec_mul(double a, t_vec3 b)
{
	t_vec3	r;

	r.x = a * b.x;
	r.y = a * b.y;
	r.z = a * b.z;
	r.w = b.w;
	return (r);
}

t_vec3	vec_div(double a, t_vec3 b)
{
	t_vec3	r;

	r.x = b.x / a;
	r.y = b.y / a;
	r.z = b.z / a;
	r.w = b.w;
	return (r);
}

t_vec3	vec_norm(t_vec3 a)
{
	t_vec3	r;
	double	mag;

	mag = magnitude(a);
	r.x = a.x / mag;
	r.y = a.y / mag;
	r.z = a.z / mag;
	r.w = a.w / mag;
	return (r);
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	t_vec3	r;

	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	r.w = a.w;	// TODO: check this
	return (r);
}