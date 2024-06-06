# include "../include/minirt.h"

/* Initialize an intersection struct and allocate it in the memory */
t_inter	*init_inter(t_minirt *data, t_shape *shape, double inter)
{
	t_inter	*new_inter;

	new_inter = (t_inter *)gc_get(data, 1, sizeof(t_inter)); //Maybe we dont need to store the nters in the gc if we use lstclear
	if (!new_inter)
	{
		perror("Failed to allocate t_inter");
		return (NULL); // Probably not needed when using the gc
	}
	new_inter->shape = shape;
	new_inter->inter = inter;
	return (new_inter);
}

t_discr	discriminant(t_sphere *sphere, t_ray ray)
{
	t_discr	r;
	t_vec3	sphere_to_ray;

	sphere_to_ray = vec_sub(ray.origin, sphere->center);
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

bool	inter_sphere(t_minirt *data, t_shape *shape, t_ray ray)
{
	t_discr	d;

	d = discriminant(&shape->sphere, ray);
	if (d.discr < 0) //no valid intersections
		return (false);
	else if (d.discr == 0) //tangent: both intersections are equal
		ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, d.t1)));
	else
	{
		ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, d.t1)));
		ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, d.t2)));
	}
	return (true);
}

bool	inter_plane(t_minirt *data, t_shape *shape, t_ray ray)
{
	double	t;
	double	tmp;

	if (ray.dir.y < 0)
	{
		tmp = -ray.dir.y;
		if (tmp < EPSILON)
			return (false);
	}
	if (ray.dir.y < EPSILON)
		return (false);
	t = -ray.origin.y / ray.dir.y; //only works for planes parallel to the xz plane
	ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, t)));
	return (true);
}

t_inter	hit(t_list *xs)
{
	t_inter	min_inter;
	t_inter	*inter;

	min_inter = (t_inter){NULL, (double)INT_MAX}; //TODO: probably we don't need this, to be optimezed
	while (xs != NULL)
	{
		inter = (t_inter *)xs->content;
		if (inter->inter <= min_inter.inter && inter->inter > 0) //TODO: change attr name? inter.inter looks ugly
			min_inter = *inter;
		xs = xs->next;
	}
	return (min_inter);
}

/* wrapper function for different shapes intersection: takes minirt struct as input*/
void	intersections(t_minirt *data, t_ray ray)
{
	t_list	*shapes; //objects might become world
	t_shape	*shape;

	shapes = data->world->objects;
	while (shapes != NULL)
	{
		shape = (t_shape *)shapes->content;
		if (shape->name == SPHERE)
			inter_sphere(data, shape, ray);
		if (shape->name == PLANE)
			inter_plane(data, shape, ray);
		shapes = shapes->next;
	}
}
