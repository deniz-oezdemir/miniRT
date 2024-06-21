/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discriminants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:17:42 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:17:54 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_discr	sphere_discriminant(t_sphere *sphere, t_ray ray)
{
	t_discr	d;
	t_vec3	sphere_to_ray;

	sphere_to_ray = vec_sub(ray.origin, sphere->center);
	d.a = vec_dot(ray.dir, ray.dir);
	d.b = 2.0 * vec_dot(ray.dir, sphere_to_ray);
	d.c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	d.discr = (d.b * d.b) - 4 * d.a * d.c;
	d.t1 = (-d.b - sqrt(d.discr)) / (2 * d.a);
	d.t2 = (-d.b + sqrt(d.discr)) / (2 * d.a);
	return (d);
}

t_discr	cylinder_discriminant(t_ray ray)
{
	t_discr	d;

	d.a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	d.b = (2.0 * ray.origin.x * ray.dir.x) + (2.0 * ray.origin.z * ray.dir.z);
	d.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1.0;
	d.discr = pow(d.b, 2) - 4.0 * d.a * d.c;
	d.t1 = (-d.b - sqrt(d.discr)) / (2 * d.a);
	d.t2 = (-d.b + sqrt(d.discr)) / (2 * d.a);
	return (d);
}

t_discr	cone_discriminant(t_ray ray)
{
	t_discr	d;

	d.a = pow(ray.dir.x, 2) - pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	d.b = (2.0 * ray.origin.x * ray.dir.x) - (2.0 * ray.origin.y * ray.dir.y)
		+ (2.0 * ray.origin.z * ray.dir.z);
	d.c = pow(ray.origin.x, 2) - pow(ray.origin.y, 2) + pow(ray.origin.z, 2);
	d.discr = pow(d.b, 2) - 4.0 * d.a * d.c;
	d.t1 = (-d.b - sqrt(d.discr)) / (2 * d.a);
	d.t2 = (-d.b + sqrt(d.discr)) / (2 * d.a);
	return (d);
}
