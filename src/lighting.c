#include "../include/minirt.h"

static void print_color_2(t_color color, char *description)
{
	printf("%s: (%f, %f, %f)\n", description, color.r, color.g, color.b);
}

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
	if (light_dot_normal <= 0)
	{
		//printf("Check: fot_norm < 0\n");
		diffuse = (t_color){0, 0, 0};
		specular = (t_color){0, 0, 0};
	}
	else
	{
		//printf("CHcek 3\n");
		diffuse = mult_color_scalar(effective_color,
			comps.shape->material.diffuse * light_dot_normal);
		reflectv = reflect(vec_neg(lightv), comps.normalv);
		reflect_dot_eye = vec_dot(reflectv, comps.eyev);
		//printf("Dot eye: %f\n", reflect_dot_eye);
		if (reflect_dot_eye <= 0)
			specular = (t_color){0, 0, 0};
		else
		{
			//printf("Check 4\n");
			factor = pow(reflect_dot_eye, comps.shape->material.shininess);
			specular = mult_color_scalar(plight->light,
				comps.shape->material.specular * factor);
			printf("factor: %f\n", factor);
			printf("comps.shape->material.specular: %f\n", comps.shape->material.specular);
			printf("plight->light: (%f, %f, %f)\n", plight->light.r, plight->light.g, plight->light.b);
		}
		print_color_2(specular, "Specular");
	}
	return (color_add(color_add(ambient, diffuse), specular));
}
