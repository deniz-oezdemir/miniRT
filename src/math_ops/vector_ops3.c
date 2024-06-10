# include "../../include/minirt.h"

t_vec3 normal_at(t_sphere *sphere, t_vec3 p)
{
	t_vec3 sphere_norm;

	// sphere_norm = vec_sub(p, sphere->center);
	sphere_norm = vec_sub(p, point(0,0,0));
	sphere_norm.w = 0.0;
	return (vec_norm(sphere_norm));
}

t_vec3 reflect(t_vec3 in, t_vec3 normal)
{
	return (vec_sub(in, vec_mul(vec_dot(in, normal), vec_mul(2.0, normal))));
}
