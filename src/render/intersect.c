#include "../../include/minirt.h"

/* Initialize an intersection struct and allocate it in the memory */
t_inter	*init_inter(t_minirt *data, t_shape *shape, double inter)
{
	t_inter	*new_inter;

	//CHECK: Maybe we dont need to store the iters in the gc if we use lstclear
	new_inter = (t_inter *)gc_get(data, 1, sizeof(t_inter));
	new_inter->shape = shape;
	new_inter->inter = inter;
	return (new_inter);
}

t_discr	sphere_discriminant(t_sphere *sphere, t_ray ray)
{
	t_discr	d;
	t_vec3	sphere_to_ray;

	sphere_to_ray = vec_sub(ray.origin, sphere->center);
	d.a = vec_dot(ray.dir, ray.dir);
	d.b = 2.0 * vec_dot(ray.dir, sphere_to_ray);
	d.c = vec_dot(sphere_to_ray, sphere_to_ray) - 1;
	d.discr = (d.b * d.b) - 4 * d.a * d.c;
	d.t1 = (-d.b - sqrt(d.discr)) / (2 * d.a);
	d.t2 = (-d.b + sqrt(d.discr)) / (2 * d.a);
	return (d);
}
t_discr	cylinder_discriminant(t_ray ray)
{
	t_discr	d;

	d.a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	d.b = (2.0 * ray.origin.x * ray.dir.x) + (2.0 * ray.origin.z * ray.dir.z);
	d.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1.0;
	d.discr = pow(d.b, 2) - 4.0 * d.a * d.c;
	d.t1 = (-d.b - sqrt(d.discr)) / (2 * d.a);
	d.t2 = (-d.b + sqrt(d.discr)) / (2 * d.a);
	return (d);
}

t_discr cone_discriminant(t_ray ray)
{
	t_discr	d;

	d.a = pow(ray.dir.x, 2) - pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	d.b = (2.0 * ray.origin.x * ray.dir.x) - (2.0 * ray.origin.y * ray.dir.y) + (2.0 * ray.origin.z * ray.dir.z);
	d.c = pow(ray.origin.x, 2) - pow(ray.origin.y, 2) + pow(ray.origin.z, 2);
	d.discr = pow(d.b, 2) - 4.0 * d.a * d.c;
	d.t1 = (-d.b - sqrt(d.discr)) / (2 * d.a);
	d.t2 = (-d.b + sqrt(d.discr)) / (2 * d.a);
	return (d);
}


static void	add_inter(t_minirt *data, t_shape *shape, double t)
{
	if(t < data->min.inter && t > EPSILON)
		data->min = (t_inter){shape, t};
}

bool	inter_sphere(t_minirt *data, t_shape *shape, t_ray ray)
{
	t_discr	d;

	d = sphere_discriminant(&shape->sphere, ray);
	if (d.discr < 0)
		return (false);
	add_inter(data, shape, d.t1);
	add_inter(data, shape, d.t2);
	//ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, d.t1)));
	//ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, d.t2)));
	return (true);
}

bool	inter_cylinder(t_minirt *data, t_shape *shape, t_ray ray)
{
	t_discr	d;
	double	y0;
	double	y1;

	d = cylinder_discriminant(ray);
	if (fabs(d.a) < EPSILON || d.discr < 0.0)
		return (false);
	if (d.t1 > d.t2)
		swap(&d.t1, &d.t2);
	y0 = ray.origin.y + d.t1 * ray.dir.y;
	y1 = ray.origin.y + d.t2 * ray.dir.y;
	if (shape->cylinder.minimum < y0 && y0 < shape->cylinder.maximum)
		add_inter(data, shape, d.t1);
		//ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, d.t1)));
	if (shape->cylinder.minimum < y1 && y1 < shape->cylinder.maximum)
		add_inter(data, shape, d.t2);
		//ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, d.t2)));
	return (true);
}

bool	inter_cone(t_minirt *data, t_shape *shape, t_ray ray)
{
	t_discr	d;
	double	y0;
	double	y1;

	d = cone_discriminant(ray);
	if (fabs(d.a) < EPSILON)
	{
		if (fabs(d.b) < EPSILON)
			return (false);
		add_inter(data, shape, -d.c / (2 * d.b));
		return (true);
	}
	if (d.discr < 0.0)
		return (false);
	if (d.t1 > d.t2)
		swap(&d.t1, &d.t2);
	y0 = ray.origin.y + d.t1 * ray.dir.y;
	y1 = ray.origin.y + d.t2 * ray.dir.y;
	if (shape->cone.minimum < y0 && y0 < shape->cone.maximum)
		add_inter(data, shape, d.t1);
	if (shape->cone.minimum < y1 && y1 < shape->cone.maximum)
		add_inter(data, shape, d.t2);
	return (true);
}

bool	inter_plane(t_minirt *data, t_shape *shape, t_ray ray)
{
	double	t;

	if (fabs(ray.dir.y) < EPSILON)
		return (false);
	t = -ray.origin.y / ray.dir.y; //only works for planes parallel to the xz plane
	if (t < EPSILON)
		return (false);
	add_inter(data, shape, t);
	//ft_lstadd_back(&data->xs, ft_lstnew(init_inter(data, shape, t)));
	return (true);
}

t_inter	hit(t_list *xs)
{
	t_inter	min_inter;
	t_inter	*inter;

	min_inter = (t_inter){NULL, (double)DBL_MAX}; //TODO: probably we don't need this, to be optimezed //initlaization to INT_MAX needed for is_shadow to work
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
	t_list	*shapes;
	t_shape	*shape;
	t_ray	local_ray;

	shapes = data->world->objects;
	data->min = (t_inter){NULL, (double)DBL_MAX};
	while (shapes != NULL)
	{
		shape = (t_shape *)shapes->content;
		local_ray = transform_ray(ray, shape); // Try to implement optimization from scratchapixel
		if (shape->name == SPHERE)
			inter_sphere(data, shape, local_ray);
		else if (shape->name == PLANE)
			inter_plane(data, shape, local_ray);
		else if (shape->name == CYLINDER)
			inter_cylinder(data, shape, local_ray);
		else if (shape->name == CONE)
			inter_cone(data, shape, local_ray);
		shapes = shapes->next;
	}
}
