/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:11:20 by denizozd          #+#    #+#             */
/*   Updated: 2024/07/01 16:48:43 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parser_error(int err_code)
{
	if (err_code == AMB_LIGHT_ERR)
		ft_putstr_fd("Error parsing Ambient light. Please check input parameters!\n", 2);
	else if (err_code == CAMERA_ERR)
		ft_putstr_fd("Error parsing Camera Please check input parameters!\n", 2);
	else if (err_code == CYLINDER_ERR)
		ft_putstr_fd("Error parsing Cylinder. Please check input parameters!\n", 2);
	else if (err_code == LIGHT_ERR)
		ft_putstr_fd("Error parsing Light. Please check input parameters!\n", 2);
	else if (err_code == PLANE_ERR)
		ft_putstr_fd("Error parsing Plane. Please check input parameters!\n", 2);
	else if (err_code == SPHERE_ERR)
		ft_putstr_fd("Error parsing Sphere. Please check input parameters!\n", 2);
	else if (err_code == CONE_ERR)
		ft_putstr_fd("Error parsing Cone. Please check input parameters!\n", 2);
	else if (err_code == MULTIPLE_OBJS)
		ft_putstr_fd("Error: multiple cameras or ambient lights detected\n", 2);
	else if (err_code == FILE_EXT_ERR)
		ft_putstr_fd("Error: incorrect file extension\n", 2);
	else if (err_code == FILE_OPEN_ERR)
		ft_putstr_fd("Error: opening file not possible\n", 2);
}

void	print_exit_msg(int exit_code)
{
	if (exit_code >= 10 && exit_code <= 20)
		parser_error(exit_code);
	else
		printf("miniRT terminated");
}
