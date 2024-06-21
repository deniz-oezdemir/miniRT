/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:17:16 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:17:32 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	add_inter(t_minirt *data, t_shape *shape, double t)
{
	if (t < data->min.inter && t > EPSILON)
		data->min = (t_inter){shape, t};
}

bool	inter_sphere(t_minirt *data, t_shape *shape, t_ray ray)
{
	t_discr	d;

	d = sphere_discriminant(&shape->sphere, ray);
	if (d.discr < 0)
		return (false);
	add_inter(data, shape, d.t1);
	add_inter(data, shape, d.t2);
	return (true);
}

bool	inter_cylinder(t_minirt *data, t_shape *shape, t_ray ray)
{
	t_discr	d;
	double	y0;
	double	y1;

	d = cylinder_discriminant(ray);
	if (fabs(d.a) < EPSILON || d.discr < 0.0)
		return (false);
	if (d.t1 > d.t2)
		swap(&d.t1, &d.t2);
	y0 = ray.origin.y + d.t1 * ray.dir.y;
	y1 = ray.origin.y + d.t2 * ray.dir.y;
	if (shape->cylinder.minimum < y0 && y0 < shape->cylinder.maximum)
		add_inter(data, shape, d.t1);
	if (shape->cylinder.minimum < y1 && y1 < shape->cylinder.maximum)
		add_inter(data, shape, d.t2);
	return (true);
}

bool	inter_cone(t_minirt *data, t_shape *shape, t_ray ray)
{
	t_discr	d;
	double	y0;
	double	y1;

	d = cone_discriminant(ray);
	if (fabs(d.a) < EPSILON)
	{
		if (fabs(d.b) < EPSILON)
			return (false);
		add_inter(data, shape, -d.c / (2 * d.b));
		return (true);
	}
	if (d.discr < 0.0)
		return (false);
	if (d.t1 > d.t2)
		swap(&d.t1, &d.t2);
	y0 = ray.origin.y + d.t1 * ray.dir.y;
	y1 = ray.origin.y + d.t2 * ray.dir.y;
	if (shape->cone.minimum < y0 && y0 < shape->cone.maximum)
		add_inter(data, shape, d.t1);
	if (shape->cone.minimum < y1 && y1 < shape->cone.maximum)
		add_inter(data, shape, d.t2);
	return (true);
}

bool	inter_plane(t_minirt *data, t_shape *shape, t_ray ray)
{
	double	t;

	if (fabs(ray.dir.y) < EPSILON)
		return (false);
	t = -ray.origin.y / ray.dir.y;
	if (t < EPSILON)
		return (false);
	add_inter(data, shape, t);
	return (true);
}
