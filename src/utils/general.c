/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:58:44 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/11 12:58:55 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	remove_newline(char **str)
{
	char	*newline_pos;

	newline_pos = ft_strchr(*str, '\n');
	if (newline_pos != NULL)
		*newline_pos = '\0';
}

double	deg_to_rad(double degrees)
{
	return (degrees * (PI / 180.0));
}

t_vec3 point(double x, double y, double z)
{
	return (t_vec3){x, y, z, 1.0};
}

t_vec3 vector(double x, double y, double z)
{
	return (t_vec3){x, y, z, 0.0};
}
