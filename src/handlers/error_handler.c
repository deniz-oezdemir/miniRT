/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:11:20 by denizozd          #+#    #+#             */
/*   Updated: 2024/07/03 17:29:22 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parser_error(int err_code)
{
	ft_putstr_fd("Error\n", 2);
	if (err_code == AMB_LIGHT_ERR)
		ft_putstr_fd("Ambient light: please check input parameters!\n", 2);
	else if (err_code == CAMERA_ERR)
		ft_putstr_fd("Camera: please check input parameters!\n", 2);
	else if (err_code == CYLINDER_ERR)
		ft_putstr_fd("Cylinder: please check input parameters!\n", 2);
	else if (err_code == LIGHT_ERR)
		ft_putstr_fd("Light: please check input parameters!\n", 2);
	else if (err_code == PLANE_ERR)
		ft_putstr_fd("Plane: please check input parameters!\n", 2);
	else if (err_code == SPHERE_ERR)
		ft_putstr_fd("Sphere: please check input parameters!\n", 2);
	else if (err_code == CONE_ERR)
		ft_putstr_fd("Cone: please check input parameters!\n", 2);
	else if (err_code == MULTIPLE_OBJS)
		ft_putstr_fd("Multiple cameras or ambient lights detected\n", 2);
	else if (err_code == FILE_EXT_ERR)
		ft_putstr_fd("Incorrect file extension\n", 2);
	else if (err_code == FILE_OPEN_ERR)
		ft_putstr_fd("File does not exist\n", 2);
	else if (err_code == FILE_COR_ERR)
		ft_putstr_fd("File corrupted\n", 2);
	else if (err_code == MEM_ALC_ERR)
		ft_putstr_fd("Memory allocation failed\n", 2);
}

void	print_exit_msg(int exit_code)
{
	if (exit_code >= 10 && exit_code <= 30)
		parser_error(exit_code);
	else
		ft_putstr_fd("miniRT terminated\n", 2);
}
