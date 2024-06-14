/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:46:45 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/14 15:37:34 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

t_vec3	vec_add(t_vec3 a, t_vec3 b)
{
	return ((t_vec3){
		a.x + b.x,
		a.y + b.y,
		a.z + b.z,
		a.w + b.w,
	});
}

t_vec3	vec_neg(t_vec3 v)
{
	return ((t_vec3){
		v.x * -1,
		v.y * -1,
		v.z * -1,
		v.w * -1,
	});
}

double	magnitude(t_vec3 v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2) + pow(v.w, 2)));
}

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}
