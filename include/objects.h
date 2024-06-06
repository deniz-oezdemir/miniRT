/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:56 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/06 12:03:42 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CAMERA,
	PNT_LIGHT,
	AMB_LIGHT
} t_obj_type;

typedef struct s_amblight
{
	double intensity;
	t_color color;
	t_color light; // color * intensity - maybe get rid of intensity and color if not needed
} t_amblight;

typedef struct s_camera{
	t_obj_type	name;
	t_vec3	center;
	t_vec3	dir;
	int		fov;
	int		hsize;
	int		vsize;
	double	half_width;
	double	half_height;
	double	pixel_size;
	t_mtx	trans_view;
}	t_camera;

typedef struct s_pntlight
{
	t_vec3 center; // position
	double intensity;
	t_color color;
	t_color light; // color * intensity - maybe get rid of intensity and color if not needed
} t_pntlight;

typedef struct s_sphere
{
	t_vec3 center;
	double diameter;
	t_color color;
} t_sphere;

typedef struct s_plane
{
	t_vec3 center;
	t_vec3 dir;
	t_color color;
} t_plane;

typedef struct s_cylinder
{
	t_vec3 center;
	t_vec3 dir;
	double diameter;
	double height;
	t_color color;
} t_cylinder;

typedef struct s_material
{
	double diffuse;
	double specular;
	double shininess;
} t_material;

typedef struct s_shape
{
	t_obj_type	name;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
	};
	t_material	material;
	t_color		color;
} t_shape;

typedef struct s_light
{
	t_obj_type name;
	union
	{
		t_amblight amb_light;
		t_pntlight pnt_light;
	};
} t_light;
