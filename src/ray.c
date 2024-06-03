# include "../include/minirt.h"

/* OLD implementation */
/* t_ray	cast_ray(t_vec3 origin, t_vec3 dir)
{
	return ((t_ray){
		origin, dir
	});
} */

t_vec3 point(double x, double y, double z)
{
	return (t_vec3){x, y, z, 1.0};
}

t_vec3 vector(double x, double y, double z)
{
	return (t_vec3){x, y, z, 0.0};
}

t_ray	cast_ray(t_camera *camera, int px, int py)
{
	double	x_offset;
	double	y_offset;
	double	world_x;
	double	world_y;
	t_vec3	pixel;
	t_vec3	origin;
	t_vec3	direction;

	x_offset = (px + 0.5) * camera->pixel_size;
	y_offset = (py + 0.5) * camera->pixel_size;
	world_x = camera->half_width - x_offset;
	world_y = camera->half_height - y_offset;
	pixel = mult_pnt_mtx(point(world_x, world_y, -1), invert_mtx(camera->trans_view));
	origin = mult_pnt_mtx(camera->center, invert_mtx(camera->trans_view));
	direction = vec_norm(vec_sub(pixel, origin));
	return ((t_ray){origin, direction});
}

t_vec3	position(t_ray ray, double dist)
{
	return (vec_add(ray.origin, vec_mul(dist, ray.dir)));
}
