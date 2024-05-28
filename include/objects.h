/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:56 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/28 11:50:38 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

typedef enum e_obj_type {
    SPHERE,
    PLANE,
	CYLINDER,
	PLANE,
	CAMERA,
	PNT_LIGHT,
	AMB_LIGHT
}	t_obj_type;

typedef struct s_amblight{
	char *name; // delete it later
	double	intensity;
	int		r;
	int		g;
	int		b;
}	t_amblight;

typedef struct s_camera{
	t_obj_type	name;
	t_vec3	center;
	t_vec3	dir;
	int		fov;
}	t_camera;

typedef struct s_light{
	t_obj_type	name;
	t_vec3	center;
	double	intensity;
	t_color	color;
}	t_light;

typedef struct s_sphere{
	t_vec3	center;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane{
	t_vec3	center;
	t_vec3	dir;
	t_color	color;
}	t_plane;

typedef struct s_cylinder{
	t_vec3	center;
	t_vec3	dir;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_shape
{
	t_obj_type	name;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
	//t_material		material;
}	t_shape;