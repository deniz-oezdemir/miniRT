/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:35:29 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/21 10:24:17 by tiacovel         ###   ########.fr       */
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
