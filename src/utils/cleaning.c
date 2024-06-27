/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:23:50 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/27 17:46:18 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* Clear the intersection list "xs" and free each node. */
void	free_inter(void *content)
{
	t_inter	*inter_content;

	inter_content = (t_inter *)content;
	inter_content->shape = NULL;
}

void	exit_program(t_minirt *data, int exit_code)
{
	if (data->mlx_img->img_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->mlx_img->img_ptr);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	if (data->mlx_img != NULL)
		free(data->mlx_img);
	gc_free(data->grbg);
	free(data);
	print_exit_msg(exit_code);
	exit(exit_code);
}
