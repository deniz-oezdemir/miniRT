#include "../../include/minirt.h"

t_ray	cast_ray(t_camera *camera, int px, int py)
{
	double	world_x;
	double	world_y;
	t_vec3	pixel;
	t_vec3	origin;
	t_vec3	direction;

	world_x = camera->half_width - (px + 0.5) * camera->pixel_size;
	world_y = camera->half_height - (py + 0.5) * camera->pixel_size;
	pixel = mult_pnt_mtx(point(world_x, world_y, -1), camera->inverse); // change with camera inverse
	origin = mult_pnt_mtx(point(0,0,0),  camera->inverse);
	direction = vec_norm(vec_sub(pixel, origin));
	return ((t_ray){origin, direction});
}

t_ray	transform_ray(t_ray ray, t_shape *shape)
{
	t_ray	trans_ray;
	t_vec3	origin;
	t_vec3	direction;

	origin = mult_pnt_mtx(ray.origin, shape->inverse);
	direction = mult_pnt_mtx(ray.dir, shape->inverse);
	trans_ray = (t_ray){origin, direction};
	return (trans_ray);
}

t_vec3	position(t_ray ray, double dist)
{
	return (vec_add(ray.origin, vec_mul(dist, ray.dir)));
}
