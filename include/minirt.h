/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/07 12:39:03 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "objects.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include <X11/keysym.h>
# include "../lib/libft/libft.h"

# define WIN_NAME	"MiniRT"
# define WIN_WIDTH	1000
# define WIN_HEIGHT	600

# define IMG_WIDTH	800
# define IMG_HEIGHT	600

# define BACKGROUND_COLOR	0x202020
# define TEXT_COLOR			0xffffff

# define MLX_ERROR	1

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_minirt
{
	int			fd;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*mlx_img;
	// t_scene	*scene;
}	t_minirt;

/* Minilib functions */
t_minirt	*init_mlx(void);
void	init_window(t_minirt *data);
void	destroy_window(t_minirt *data);

/* MLX keyboard and mouse hooks */
int		handle_keyboard_input(int keysym, t_minirt *data);
int		handle_mouse_input(int keysym, t_minirt *data);
int		handle_close_button(t_minirt *data);

/* Window functions */
void	color_pixel(t_minirt *data, int x, int y, int color);
void	color_background(t_minirt *data, int color);
void	print_instruction(t_minirt *data);

#endif
