/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:33:54 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/20 17:55:28 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	color_pixel(t_minirt *data, int x, int y, int color)
{
	int	offs;

	if ((x < IMG_WIDTH && y < IMG_HEIGHT) && (x > 0 && y > 0))
	{
		offs = (data->mlx_img->line_len * y) + (x * (data->mlx_img->bits_per_pixel / 8));
		*((unsigned int *)(offs + data->mlx_img->img_pixels_ptr)) = color;
	}
}

void	color_background(t_minirt *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < IMG_HEIGHT)
	{
		x = 0;
		while (x < IMG_WIDTH)
		{
			color_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_instruction(t_minirt *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx_ptr;
	win = data->mlx_win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "MiniRT - Commands");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom:");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Out: - 1");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "In - 2");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move:");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "X-Axis - Lft/Right");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Y-Axis - Up/Down ");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "X-Axis - W/S");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Y-Axis - A/D");
	mlx_string_put(mlx, win, 50, y += 25, TEXT_COLOR, "Z-Axis - Q/E");
}