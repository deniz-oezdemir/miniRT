/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:56 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/27 17:37:40 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

typedef enum e_shape_type {
    SPHERE,
    PLANE,
	CYLINDER
}	t_shape_type;

typedef struct s_amblight{
	char *name; // delete it later
	double	intensity;
	int		r;
	int		g;
	int		b;
}	t_amblight;

typedef struct s_camera{
	char *name; // delete it later
	double	x;
	double	y;
	double	z;
	int		xv;
	int		yv;
	int		zv;
	int		fov;
}	t_camera;

typedef struct s_light{
	char *name; // delete it later
	double	x;
	double	y;
	double	z;
	double	intensity;
	int		r;
	int		g;
	int		b;
}	t_light;

typedef struct s_sphere{
	t_vec3	center;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane{
	char *name; // delete it later
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
	char *name; // delete it later
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

typedef struct s_shape
{
	t_shape_type	name;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	} ;
	//t_material		material;
}	t_shape;