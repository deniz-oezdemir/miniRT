#include "../../include/minirt.h"

t_vec3 reflect(t_vec3 in, t_vec3 normal)
{
	return (vec_sub(in, vec_mul(vec_dot(in, normal), vec_mul(2.0, normal))));
}

static t_color	dark_exposure(t_color ambient, t_exposure e)
{
	t_color	diffuse;
	t_color	specular;

	diffuse = (t_color){0, 0, 0};
	specular = (t_color){0, 0, 0};
	return (color_add(color_add(ambient, diffuse), specular));
}

static t_color	light_exposure(t_color ambient, t_pntlight *plight,
									t_exposure e, t_comps comps)
{
	t_color	diffuse;
	t_color	specular;

	diffuse = mult_color_scalar(e.effective_color, comps.shape->material.diffuse * e.light_dot_normal);
	e.reflectv = reflect(vec_neg(e.lightv), comps.normalv);
	e.reflect_dot_eye = vec_dot(e.reflectv, comps.eyev);
	if (e.reflect_dot_eye <= 0)
		specular = (t_color){0, 0, 0};
	else
	{
		e.factor = pow(e.reflect_dot_eye, comps.shape->material.shininess);
		specular = mult_color_scalar(plight->light,
			comps.shape->material.specular * e.factor);
	}
	return (color_add(color_add(ambient, diffuse), specular));
}

t_color	lighting(t_comps comps, t_color ambient, t_pntlight *plight)
{
	t_color	diffuse;
	t_color	specular;
	t_exposure	e;

	e.effective_color = mult_colors(comps.shape->color, plight->light);
	e.lightv = vec_norm(vec_sub(plight->center, comps.point));
	e.light_dot_normal = vec_dot(e.lightv, comps.normalv);
	if (e.light_dot_normal <= 0 || plight->shadow == 1)
		return (dark_exposure(ambient, e));
	else
		return (light_exposure(ambient, plight, e, comps));
}
