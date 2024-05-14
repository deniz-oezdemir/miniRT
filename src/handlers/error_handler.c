/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:46:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 15:56:35 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

void	pars_error(int err_code)
{
	if (err_code == AMB_LIGHT_ERR)
		perror("Error parsing Ambient light. Please check input parameters!");
	else if (err_code == CAMERA_ERR)
		perror("Error parsing Camera Please check input parameters!");
	else if (err_code == CYLINDER_ERR)
		perror("Error parsing Cylinder. Please check input parameters!");
	else if (err_code == LIGHT_ERR)
		perror("Error parsing Light. Please check input parameters!");
	else if (err_code == PLANE_ERR)
		perror("Error parsing Plane. Please check input parameters!");
    else if (err_code == SPHERE_ERR)
		perror("Error parsing Sphere. Please check input parameters!");
    // Add memory clean functions
    exit(err_code);
}