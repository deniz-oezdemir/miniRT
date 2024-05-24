# include "../include/minirt.h"

t_ray	get_ray(t_vec3 origin, t_vec3 dir)
{
	return ((t_ray){
		origin, dir
	});
}
t_vec3	position(t_ray ray, double dist)
{
	return (vec_add(ray.origin, vec_mul(dist, ray.dir)));
}
