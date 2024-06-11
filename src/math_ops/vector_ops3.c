# include "../../include/minirt.h"

t_vec3 normal_at_sphere(t_shape *shape, t_vec3 p)
{
	t_vec3	sphere_norm;

	(void) shape;
	sphere_norm = vec_sub(p, point(0,0,0));
	sphere_norm.w = 0.0;
	return (vec_norm(sphere_norm));
}

t_vec3	normal_at_plane(t_shape *shape, t_vec3 world_point)
{
	(void) shape;
	(void) world_point;
	return (vector(0, 1, 0));
}

t_vec3	normal_at(t_shape *shape, t_vec3 p)
{
	t_vec3	normal;

	if (shape->name == SPHERE)
		normal = normal_at_sphere(shape, p);				
	if (shape->name == PLANE)
		normal = normal_at_plane(shape, p);
	return (normal);
}
