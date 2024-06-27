/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:11:20 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/27 17:41:47 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parser_error(int err_code)
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
	else if (err_code == MULTIPLE_OBJS)
		perror("Error: multiple cameras or ambient lights detected\n");
}

void	print_exit_msg(int exit_code)
{
	if (exit_code >= 10 && exit_code <= 20)
		parser_error(exit_code);
	else
		printf("miniRT terminated");
}
