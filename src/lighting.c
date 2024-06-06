#include "../include/minirt.h"

t_color	lighting(t_comps comps, t_amblight *ambient_light, t_pntlight *plight)
{
	t_color	effective_color;
	t_vec3	lightv;
	t_vec3	reflectv;
	t_color	ambient;
	double	light_dot_normal;
	t_color	diffuse;
	t_color	specular;
	double	reflect_dot_eye;
	double	factor;

	effective_color = mult_colors(comps.shape->color, plight->light);
	lightv = vec_norm(vec_sub(plight->center, comps.point));
	ambient = mult_colors(effective_color, ambient_light->light);
	light_dot_normal = vec_dot(lightv, comps.normalv);
	if (light_dot_normal < 0)
	{
		diffuse = (t_color){0, 0, 0};
		specular = (t_color){0, 0, 0};
	}
	else
	{
		diffuse = mult_color_scalar(effective_color, 
			comps.shape->material.diffuse * light_dot_normal);
		reflectv = reflect(vec_neg(lightv), comps.normalv);
		reflect_dot_eye = vec_dot(reflectv, comps.eyev);
		if (reflect_dot_eye <= 0)
			specular = (t_color){0, 0, 0};
		else
		{
			factor = pow(reflect_dot_eye, comps.shape->material.shininess);
			specular = mult_color_scalar(plight->light,
				comps.shape->material.specular * factor);
		}
	}
	return (color_add(color_add(ambient, diffuse), specular));
}
