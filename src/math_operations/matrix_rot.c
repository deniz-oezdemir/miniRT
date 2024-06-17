/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:35:29 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/14 16:02:59 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* Calculates the rotation angles for a given vector. */
static t_mtx	calculate_rotation_matrix(t_minirt *data, double x_angle, double y_angle,
	double z_angle)
{
	t_mtx	rotate_x;
	t_mtx	rotate_y;
	t_mtx	rotate_z;

	rotate_x = rot_x(data, x_angle);
	rotate_y = rot_y(data, y_angle);
	rotate_z = rot_z(data, z_angle);
	return (mult_mtx_mtx(data, rotate_y, mult_mtx_mtx(data, rotate_x, rotate_z)));
}

t_mtx	rotation_mtx(t_minirt *data, t_vec3 vector)
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	t_mtx	rotation_mtx;

	calculate_rotation_angles(vector, &x_angle, &y_angle, &z_angle);
	rotation_mtx = calculate_rotation_matrix(data, x_angle, y_angle, z_angle);
	return (rotation_mtx);
}

t_mtx	rot_x(t_minirt *data, double radians)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{1, 0, 0, 0},
	{0, cos(radians), -sin(radians), 0},
	{0, sin(radians), cos(radians), 0},
	{0, 0, 0, 1}};

	return (create_mtx(data, (const double *)r, MTX_DIM));
}

t_mtx	rot_y(t_minirt *data, double radians)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{cos(radians), 0, sin(radians), 0},
	{0, 1, 0, 0},
	{-sin(radians), 0, cos(radians), 0},
	{0, 0, 0, 1}};

	return (create_mtx(data, (const double *)r, MTX_DIM));
}

t_mtx	rot_z(t_minirt *data, double radians)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{cos(radians), -sin(radians), 0, 0},
	{sin(radians), cos(radians), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};

	return (create_mtx(data, (const double *)r, MTX_DIM));
}
