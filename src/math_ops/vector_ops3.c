# include "../../include/minirt.h"

t_vec3	normal_at_sphere(t_shape *shape, t_vec3 world_point)
{
	t_vec3	sphere_norm;

	(void) shape;
	sphere_norm = vec_sub(world_point, point(0,0,0));
	sphere_norm.w = 0.0;
	return (vec_norm(sphere_norm));
}

t_vec3	normal_at_plane(t_shape *shape, t_vec3 world_point)
{
	(void) world_point;
	return (shape->plane.dir); // Check if we need to normalize 
}

t_vec3	normal_at_cylinder(t_shape *shape, t_vec3 world_point)
{
	double	dist;

	dist = pow(world_point.x, 2) + pow(world_point.z, 2);
	if (dist < 1.0 && world_point.y >= shape->cylinder.maximum - EPSILON)
		return (vector(0, 1, 0));
	if (dist < 1.0 && world_point.y <= shape->cylinder.minimum + EPSILON)
		return (vector(0, -1, 0));
	return (vector(world_point.x, 0.0, world_point.z)); // Check if we need to normalize 
}

t_vec3	normal_at(t_shape *shape, t_vec3 world_point)
{
	t_vec3	world_normal;
	t_vec3	object_point;
	t_vec3	object_normal;

	//Something to be added here
	object_point = mult_pnt_mtx(world_point, shape->inverse);
	if (shape->name == SPHERE)
		object_normal = normal_at_sphere(shape, object_point);				
	else if (shape->name == PLANE)
		object_normal = normal_at_plane(shape, object_point);
	else if (shape->name == CYLINDER)
		object_normal = normal_at_cylinder(shape, object_point);
	world_normal = mult_pnt_mtx(object_normal, shape->transpose);
	world_normal.w = 0.0;
	return (vec_norm(world_normal));
}
