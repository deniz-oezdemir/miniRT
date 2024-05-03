/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:50:17 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/03 15:05:21 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_mlx_data	*init_mlx(void)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (data == NULL)
		exit (MLX_ERROR);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data);
		exit (MLX_ERROR);
	}
	data->mlx_win = NULL;
	data->img.img_ptr = NULL;
	data->img.img_pixels_ptr = NULL;
	return (data);
}

void	init_window(t_mlx_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (data->mlx_win == NULL)
		destroy_window(data);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	if (data->img.img_ptr == NULL)
		destroy_window(data);
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	if (data->img.img_pixels_ptr == NULL)
		destroy_window(data);
	/* mlx_key_hook(data->mlx_win, handle_keyboard_input, data);
	mlx_hook(data->mlx_win, 17, 0, handle_close_button, data);
	mlx_mouse_hook(data->mlx_win, handle_mouse_input, data); */
}

/* void	init_camera(t_mlx_data *data)
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
		data->img.img_ptr, 200, 0);
} */
