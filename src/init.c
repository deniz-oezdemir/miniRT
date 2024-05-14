/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 17:08:27 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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

/* void	init_camera(t_minirt *data)
{
	data->view.rot_x = -45;
	data->view.rot_y = -20;
	data->view.rot_z = 20;
	data->view.zoom = calculate_zoom_factor(data);
	data->origin.x0 = 100;
	data->origin.y0 = 100;
	data->view.z_factor = 1;
	print_instruction(data);
	transform_nodes(data->map, data->view, data->origin);
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img->img_ptr, 200, 0);
} */
