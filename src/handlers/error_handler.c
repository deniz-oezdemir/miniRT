/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:11:20 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:11:39 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	pars_error(t_minirt *data, int err_code)
{
	if (err_code == AMB_LIGHT_ERR)
		perror("Error parsing Ambient light. Please check input parameters!\n");
	else if (err_code == CAMERA_ERR)
		perror("Error parsing Camera Please check input parameters!\n");
	else if (err_code == CYLINDER_ERR)
		perror("Error parsing Cylinder. Please check input parameters!\n");
	else if (err_code == LIGHT_ERR)
		perror("Error parsing Light. Please check input parameters!\n");
	else if (err_code == PLANE_ERR)
		perror("Error parsing Plane. Please check input parameters!\n");
	else if (err_code == SPHERE_ERR)
		perror("Error parsing Sphere. Please check input parameters!\n");
	else if (err_code == CONE_ERR)
		perror("Error parsing Cone. Please check input parameters!\n");
	// Add memory clean functions
	exit_program(data);
	exit(err_code);
}
