/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:56 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/31 18:55:26 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

typedef enum e_obj_type {
    SPHERE,
    PLANE,
	CYLINDER,
	CAMERA,
	PNT_LIGHT,
	AMB_LIGHT
}	t_obj_type;

typedef struct s_amblight{
	double	intensity;
	t_color	color;
}	t_amblight;

typedef struct s_camera{
	t_obj_type	name;
	t_vec3	center;
	t_vec3	dir;
	int		fov;
}	t_camera;

//duplicate?
typedef struct s_pntlight{
	t_vec3	center;
	double	intensity;
	t_color	color;
}	t_pntlight;

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

//lighting
typedef struct s_pointlight{
	t_vec3	position;
	t_color intensity;
}	t_pointlight;

typedef struct s_material{
	t_color		color;
	t_color		ambient; //might need to be changed to t_amblight or t_color
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

typedef struct s_shape
{
	t_obj_type	name;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
	t_material		material;
}	t_shape;

typedef struct s_light
{
	t_obj_type	name;
	union
	{
		t_amblight	amb_light;
		t_pntlight	pnt_light;
	};
}	t_light;



