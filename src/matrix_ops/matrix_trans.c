/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:57:46 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/21 10:24:15 by tiacovel         ###   ########.fr       */
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
