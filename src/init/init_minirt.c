/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/06 12:33:33 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* rename init minirt and img */
t_minirt	*init_mlx(void)
{
	t_minirt	*data;

	data = (t_minirt *)ft_calloc(1, sizeof(t_minirt));
	if (data == NULL)
		exit (MLX_ERROR);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data);
		exit (MLX_ERROR);
	}
	data->mlx_win = NULL;
	data->mlx_img = (t_img *)ft_calloc(1, sizeof(t_img)); //check and free
	if (data->mlx_img == NULL)
		exit (MLX_ERROR);
	data->mlx_img->img_pixels_ptr = NULL;
	data->fd = 0;
	data->scene = NULL;
	data->objects = NULL;
	data->grbg = NULL;
	data->world = (t_world *)ft_calloc(1, sizeof(t_world));
	return (data);
}

void	init_window(t_minirt *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (data->mlx_win == NULL)
		exit_program(data);
	data->mlx_img->img_ptr = mlx_new_image(data->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	if (data->mlx_img->img_ptr == NULL)
		exit_program(data);
	data->mlx_img->img_pixels_ptr = mlx_get_data_addr(data->mlx_img->img_ptr,
			&data->mlx_img->bits_per_pixel, &data->mlx_img->line_len, \
			&data->mlx_img->endian);
	if (data->mlx_img->img_pixels_ptr == NULL)
		exit_program(data);
	mlx_key_hook(data->mlx_win, handle_keyboard_input, data);
	mlx_hook(data->mlx_win, 17, 0, handle_close_button, data);
	mlx_mouse_hook(data->mlx_win, handle_mouse_input, data);
}

void	init_camera_view(t_camera *camera)
{
	double		half_view;
	double		aspect;

	// camera = data->world->camera;
	camera->trans_view = identity_mtx(4);
	camera->hsize = IMG_WIDTH;
	camera->vsize = IMG_HEIGHT;
	aspect = camera->hsize / camera->vsize;
	half_view = tan((deg_to_rad(camera->fov))/2);
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / (double)camera->hsize;
}
