# include "../include/minirt.h"

t_inter inter_sphere(void *object, t_ray ray)
{
	t_inter r;
	t_discr d;

	d = discriminant((t_sphere *)object, ray);
	printf("discriminant: %.9f\n", d.discr);
	if (d.discr < 0)
		r.count = 0; // future optimization: do not execute anything else in this function
	else if (d.discr == 0)
		r.count = 1;
	else if (d.discr > 0)
		r.count = 2;
	r.name = ((t_sphere *)object)->name;
	r.i1 = d.t1;
	r.i2 = d.t2;
	return (r);
}

t_discr discriminant(t_sphere *sphere, t_ray ray)
{
	t_discr	r;
	t_vec3	sphere_to_ray;

	sphere_to_ray = vec_sub(ray.origin, (t_vec3){0, 0, 0, 1});
	r.a = vec_dot(ray.dir, ray.dir);
	r.b = 2.0 * vec_dot(ray.dir, sphere_to_ray);
	r.c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	r.discr = (r.b * r.b) - 4 * r.a * r.c;
	if (r.discr < 0) //small optimization
	{
		r.t1 = 0;
		r.t2 = 0;
	}
	else
	{
	r.t1 = (-r.b - sqrt(r.discr)) / (2 * r.a);
	r.t2 = (-r.b + sqrt(r.discr)) / (2 * r.a);
	}
	return (r);
}
