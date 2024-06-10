#include "../include/minirt.h"

t_color	lighting(t_comps comps, t_color ambient, t_pntlight *plight)
{
	t_color	effective_color;
	t_vec3	lightv;
	t_vec3	reflectv;
	double	light_dot_normal;
	t_color	diffuse;
	t_color	specular;
	double	reflect_dot_eye;
	double	factor;

	effective_color = mult_colors(comps.shape->color, plight->light);
	print_color(effective_color, "Effective color");
	print_vec3(plight->center, "Point Light position");
	print_vec3(comps.point, "Point");
	lightv = vec_norm(vec_sub(plight->center, comps.point));
	print_vec3(lightv, "Light Vec");
	// ambient = mult_colors(effective_color, ambient_light->light);
	light_dot_normal = vec_dot(lightv, comps.normalv);
	printf("Light Dot normal: %f\n", light_dot_normal);
	if (light_dot_normal < 0)
	{
		printf("Check: fot_norm < 0\n");
		diffuse = (t_color){0, 0, 0};
		specular = (t_color){0, 0, 0};
	}
	else
	{
		printf("Light exposure TEST:\n");
		diffuse = mult_color_scalar(effective_color, 
			comps.shape->material.diffuse * light_dot_normal);
		print_color(diffuse, "Effective color");
		reflectv = reflect(vec_neg(lightv), comps.normalv);
		print_vec3(reflectv, "Reflect Vec");
		reflect_dot_eye = vec_dot(reflectv, comps.eyev);
		printf("Dot eye: %f\n", reflect_dot_eye);
		if (reflect_dot_eye <= 0)
			specular = (t_color){0, 0, 0};
		else
		{
			factor = pow(reflect_dot_eye, comps.shape->material.shininess);
			printf("Factor: %f\n", factor);
			specular = mult_color_scalar(plight->light,
				comps.shape->material.specular * factor);
			print_color(specular, "Specular color");
		}
	}
	return (color_add(color_add(ambient, diffuse), specular));
}
