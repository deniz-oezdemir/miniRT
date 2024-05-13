/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:56 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/13 13:43:50 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_amblight{
	char	*name;
	double	intensity;
	int		r;
	int		g;
	int		b;
}	t_amblight;

typedef struct s_camera{
	char	*name;
	double	x;
	double	y;
	double	z;
	int		xv;
	int		yv;
	int		zv;
	int		fov;
}	t_camera;

typedef struct s_light{
	char	*name;
	double	x;
	double	y;
	double	z;
	double	intensity;
	int		r;
	int		g;
	int		b;
}	t_light;

typedef struct s_sphere{
	char	*name;
	double	x;
	double	y;
	double	z;
	double	diameter;
	int		r;
	int		g;
	int		b;
}	t_sphere;

typedef struct s_plane{
	char	*name;
	double	x;
	double	y;
	double	z;
	int		xv;
	int		yv;
	int		zv;
	int		r;
	int		g;
	int		b;
}	t_plane;

typedef struct s_cylinder{
	char	*name;
	double	x;
	double	y;
	double	z;
	int		xv;
	int		yv;
	int		zv;
	double	diameter;
	double	height;
	int		r;
	int		g;
	int		b;
}	t_cylinder;