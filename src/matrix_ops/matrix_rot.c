/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:35:29 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/06 12:58:18 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_mtx	rot_x(double radians)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{1, 0, 0, 0},
	{0, cos(radians), -sin(radians), 0},
	{0, sin(radians), cos(radians), 0},
	{0, 0, 0, 1}};

	return (create_mtx((const double *)r, MTX_DIM));
}

t_mtx	rot_y(double radians)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{cos(radians), 0, sin(radians), 0},
	{0, 1, 0, 0},
	{-sin(radians), 0, cos(radians), 0},
	{0, 0, 0, 1}};

	return (create_mtx((const double *)r, MTX_DIM));
}

t_mtx	rot_z(double radians)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{cos(radians), -sin(radians), 0, 0},
	{sin(radians), cos(radians), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	return (create_mtx((const double *)r, MTX_DIM));
}

static void	rotation_angles(t_vec3 vec, double *x, double *z)
{
	double	projection;

	projection = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	if (0.0 == projection)
		*z = PI_2;
	else
		*z = acos(vec.y / projection);
	*x = acos(projection);
}

t_mtx	rotation_mtx(t_vec3 vec)
{
	double		x_angle;
	double		z_angle;
	t_mtx	z_rot;
	t_mtx	x_rot;
	t_mtx	full_rotation;

	rotation_angles(vec, &x_angle, &z_angle);
	z_rot = rot_z(z_angle);
	x_rot = rot_x(x_angle);
	full_rotation = mult_mtx_mtx(z_rot, x_rot);
	return (full_rotation);
}
