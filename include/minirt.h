/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/03 15:35:35 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
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

# define MLX_ERROR	1

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
}	t_mlx_data;

/* Minilib functions */
t_mlx_data	*init_mlx(void);
void	init_window(t_mlx_data *data);

#endif
