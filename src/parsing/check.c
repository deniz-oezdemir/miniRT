/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/21 09:33:26 by denizozd         ###   ########.fr       */
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
		return ((double)(-1.0 - INT_MAX));
	coord = atof(arg);
	if (!is_in_range(INT_MIN, INT_MAX, arg))
		return ((double)(-1.0 - INT_MAX));
	return (coord);
}

int	check_vec3(char *arg)
{
	int	vec;

	vec = -99;
	if (!is_digits(arg))
		return (-2);
	vec = ft_atoi(arg);
	if (!is_in_range(-1, 1, arg))
		return (-2);
	return (vec);
}

int	check_fov(char *arg)
{
	int	fov;

	fov = -99;
	if (!is_digits(arg))
		return (-1);
	fov = ft_atoi(arg);
	if (!is_in_range(0, 180, arg))
		return (-1);
	return (fov);
}
