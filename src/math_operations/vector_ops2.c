/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:57:19 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/21 09:23:55 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	vec_sub(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
		a.w - b.w
	});
}

t_vec3	vec_mul(double a, t_vec3 b)
{
	return ((t_vec3){
		a * b.x,
		a * b.y,
		a * b.z,
		b.w
	});
}

t_vec3	vec_div(double a, t_vec3 b)
{
	return ((t_vec3){
		b.x / a,
		b.y / a,
		b.z / a,
		b.w
	});
}

t_vec3	vec_norm(t_vec3 a)
{
	double	mag;

	mag = magnitude(a);
	return ((t_vec3){
		a.x / mag,
		a.y / mag,
		a.z / mag,
		a.w / mag
	});
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
		a.w
	});
}
