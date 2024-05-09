/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/08 16:57:31 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	check_intensity(char *arg)
{
	double	intensity;

	intensity = -99;
	if (!is_digits(arg))
		return (-1);
	intensity = atof(arg);
	if (!is_in_range(0, 1, arg))
		return (-1);
	return (intensity);
}

int	check_rgb(char *arg)
{
	int	color;

	color = -99;
	if (!is_digits(arg))
		return (-1);
	color = ft_atoi(arg);
	if (!is_in_range(0, 255, arg))
		return (-1);
	return (color);
}

double	check_coordinate(char *arg)
{
	double	coord;

	coord = -99;
	if (!is_digits(arg))
		return (-1);
	coord = atof(arg);
	if (!is_in_range(INT_MIN, INT_MIN, arg))
		return (-1);
	return (coord);
}