/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:35:29 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/11 12:46:38 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* Calculates the rotation angles for a given vector. */
static void	calculate_rotation_angles(t_vec3 vec, double *x, double *z)
{
	double	ratio;

	ratio = sqrt((vec.x * vec.x) + (vec.y * vec.y));
	if (0.0 == ratio)
		*z = M_PI_2;
	else
		*z = acos(vec.y / ratio);
	*x = acos(ratio);
}

t_mtx	rotation_mtx(t_vec3 vector)
{
	double	x_angle;
	double	z_angle;
	t_mtx	rotate_z;
	t_mtx	rotate_x;
	t_mtx	rotation_mtx;

	calculate_rotation_angles(vector, &x_angle, &z_angle);
	rotate_z = rot_z(z_angle);
	rotate_x = rot_x(x_angle);
	rotation_mtx = mult_mtx_mtx(rotate_z, rotate_x);
	return (rotation_mtx);
}

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
