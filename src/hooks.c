/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:52:31 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/07 11:56:51 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	handle_keyboard_input(int keysym, t_minirt *data)
{
	if (keysym == XK_Escape)
		destroy_window(data);
	printf("The %d key has been pressed\n\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, 
		data->mlx_img->img_ptr, 200, 0);
	return (0);
}

int	handle_mouse_input(int keysym, t_minirt *data)
{
	(void)data;
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	handle_close_button(t_minirt *data)
{
	destroy_window(data);
	return (0);
}