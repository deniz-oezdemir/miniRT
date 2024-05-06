/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/06 12:58:10 by denizozd         ###   ########.fr       */
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
	t_list		*objects;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*mlx_img;
	// t_scene	*scene;
}	t_minirt;

/* Minilib functions */
t_minirt	*init_mlx(void);
void	init_window(t_minirt *data);
void	destroy_window(t_minirt *data);

/* Parsing */
void	file_to_list(t_minirt *data);
void	seperate_by_comma(t_minirt *data, char *space_seperated);

#endif
