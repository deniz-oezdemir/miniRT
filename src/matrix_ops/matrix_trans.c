/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:57:46 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/23 15:26:06 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_mtx	translation_mtx(double x, double y, double z)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{1, 0, 0, x},
	{0, 1, 0, y},
	{0, 0, 1, z},
	{0, 0, 0, 1}
	};

	return (create_mtx((const double *)r, MTX_DIM));
}

t_mtx	scaling(double x, double y, double z)
{
	const double	r[MTX_DIM][MTX_DIM] = {
	{x, 0, 0, 0},
	{0, y, 0, 0},
	{0, 0, z, 0},
	{0, 0, 0, 1},
	};

	return (create_mtx((const double *)r, MTX_DIM));
}
