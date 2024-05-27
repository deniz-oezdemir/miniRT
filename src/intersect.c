# include "../include/minirt.h"

/* wrapper function for different shapes intersection: takes minirt struct as input*/
void intersections(t_minirt *data, t_ray ray)
{
	t_list *tmp = data->objects; //objects might become world
	while (tmp)
	{
		//check what type of object
		inter_sphere(sphere, ray, data->xs); //sphere tbd
		tmp = tmp->next;
	}
}

bool inter_sphere(void *object, t_ray ray, t_list *xs)
{
	t_discr d;

	d = discriminant((t_sphere *)object, ray);
	if (d.discr < 0) //no valid intersections
		return (false);
	else if (d.discr == 0) //tangent: both intersections are equal
		ft_lstadd_back(&xs, ft_lstnew(&((t_inter){object, d.t1})));
	else
	{
		ft_lstadd_back(&xs, ft_lstnew(&((t_inter){object, d.t1})));
		ft_lstadd_back(&xs, ft_lstnew(&((t_inter){object, d.t2})));
	}
	return (true);
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
