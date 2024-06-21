/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:20:27 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:20:45 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	color_add(t_color a, t_color b)
{
	return ((t_color){a.r + b.r, a.g + b.g, a.b + b.b});
}

t_color	mult_colors(t_color a, t_color b)
{
	return ((t_color){a.r * b.r, a.g * b.g, a.b * b.b});
}

t_color	mult_color_scalar(t_color color, double scalar)
{
	return ((t_color){
		color.r * scalar,
		color.g * scalar,
		color.b * scalar,
	});
}

/* Check what it does */
static int	convert(double color)
{
	if (color > 1)
		color = 1;
	color *= 255 + 0.5;
	return (color);
}

int	rgb(t_color color)
{
	return (convert(color.r) << 16 | convert(color.g) << 8 | convert(color.b));
}
