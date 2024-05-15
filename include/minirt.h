/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:51:35 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/15 10:59:06 by denizozd         ###   ########.fr       */
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
# include "errors.h"

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
	t_list		*grbg;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*mlx_img;
	// t_scene	*scene;
}	t_minirt;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

/* Minilib functions */
t_minirt	*init_mlx(void);
void	init_window(t_minirt *data);
void	exit_program(t_minirt *data);

/* MLX keyboard and mouse hooks */
int		handle_keyboard_input(int keysym, t_minirt *data);
int		handle_mouse_input(int keysym, t_minirt *data);
int		handle_close_button(t_minirt *data);

/* Window functions */
void	color_pixel(t_minirt *data, int x, int y, int color);
void	color_background(t_minirt *data, int color);
void	print_instruction(t_minirt *data);

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

double	check_intensity(char *arg);
int		check_rgb(char *arg);
double	check_coordinate(char *arg);
int		check_vec3(char *arg);
int		check_fov(char *arg);

/* Handlers */
void	pars_error(t_minirt *data, int err_code);

/* utils */
double	atof(const char *str);
void	remove_newline(char **str);
void	*get_nth_content(t_list *list, int n);
void	move_to_nth_node(t_list **list, int n);
void	print_list(t_list *head);

/* Garbage collector */
void	*gc_get(t_minirt *data, size_t nmemb, size_t size);
void	gc_collect(t_minirt *data, void *new);
void	gc_free(t_list *grbg);

t_list	*gc_lstnew(t_minirt *data, void *content);
char	**gc_split(t_minirt *data, char const *s, char c);
char	*gc_substr(t_minirt *data, char const *s, unsigned int start,
		size_t len);

/* Matrix */
int	***init_matrix(t_minirt *data, int row, int col);

/* Vector operations */
t_vec3	vec_add(t_vec3 a, t_vec3 b);
void	test_vec_ops(); //delete
void	print_vec3(t_vec3 v, char* label); //delete

#endif
