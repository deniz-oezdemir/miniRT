/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/13 13:06:02 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "objects.h"
# include <stdbool.h>
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
	t_list		*scene;
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
void	parse(t_minirt *data, char *file_name);
void	parse_ambient_light(t_minirt *data, t_list **al);
void	parse_camera(t_minirt *data, t_list **list);
void	parse_light(t_minirt *data, t_list **list);
void	parse_sphere(t_minirt *data, t_list **list);
void	parse_plane(t_minirt *data, t_list **list);
void	parse_cylinder(t_minirt *data, t_list **list);

/* Input validation */
bool	is_digits(char *s);
bool	is_identifier(char *s);
bool	is_in_range(double min, double max, char *s);
bool	is_rgb(char *s);

double	check_intensity(char *arg);
int		check_rgb(char *arg);
double	check_coordinate(char *arg);

/* utils */
double	atof(const char *str);
void	remove_newline(char **str);

#endif
