#include "../include/minirt.h"

t_comps	prepare_computations(t_inter inter, t_ray ray)
{
	t_comps	comps;

	int test;
	if (inter.shape->name == PLANE)
		test = 10;

	comps.t = inter.inter;
	comps.shape = inter.shape;
	comps.point = position(ray, inter.inter);
	comps.eyev = vec_neg(ray.dir);
	comps.normalv = normal_at(inter.shape, comps.point);
	comps.inside = false;
	if (vec_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = vec_neg(comps.normalv);
	}
	comps.over_point = vec_add(comps.point, vec_mul(EPSILON, comps.normalv));
	return (comps);
}

int		is_shadow(t_minirt *data, t_vec3 light_position, t_vec3 over_point)
{
	t_vec3	v;
	t_ray	ray;
	t_inter	inter;
	t_inter	hit_inter;

	v = vec_sub(light_position, over_point);
	ray = (t_ray){over_point, vec_norm(v)};
	intersections(data, ray);
	hit_inter = hit(data->xs);
	ft_lstclear(&data->xs, free_inter);
	if (hit_inter.inter < magnitude(v)) //ommitted is_hit flag as we initialize hit_inter.inter to MAX INT and only update it if we hit something
		return (1);
	return (0);
}

t_color	shade_hit(t_minirt *data, t_world *world, t_comps comps)
{
	t_color		color;
	t_color		ambient;
	t_list		*lights;
	t_pntlight	*light;

	int test;
	if (comps.shape->name == PLANE)
		test = 10;
	lights = world->lights;
	ambient =  mult_colors(comps.shape->color, world->ambient_light->light); // check if we need a material ambient ligh like in the other project
	if (lights == NULL)
		return (ambient);
	color = (t_color){0, 0, 0};
	while (lights != NULL)
	{
		light = &((t_light *)lights->content)->pnt_light;
		light->shadow = is_shadow(data, light->center, comps.over_point);
		color = color_add(color, lighting(comps, ambient, light));
		lights = lights->next;
	}
	return (color);
}

t_color	color_at(t_minirt *data, t_ray ray)
{
	t_inter	hit_inter;
	t_comps	comps;
	t_color	color;

	color = (t_color){0.125, 0.125, 0.125}; // Background color
	intersections(data, ray);
	hit_inter = hit(data->xs);
	ft_lstclear(&data->xs, free_inter); //free before needed for shadow to work
	if (hit_inter.shape != NULL)
	{
		comps = prepare_computations(hit_inter, ray);
		color = shade_hit(data, data->world, comps);
	}
	//ft_lstclear(&data->xs, free_inter); //free after not needed?
	return (color);
}

void render_scene(t_minirt *data)
{
	double	x;
	double	y;
	t_ray	ray;
	t_color	color;

	print_instruction(data);
	//color_background(data, BACKGROUND_COLOR);
	y = -1.0;
	ft_printf("Start rendering...\n");

	while (++y < data->world->camera->vsize)
	{
		++y; //dirty optimization
		ft_printf("\rRendering: %d%%", (int)(y * 100.0 / IMG_HEIGHT));
		x = -1.0;
		while (++x < data->world->camera->hsize)
		{
			++x; //dirty optimization
			// printf("x = %f | y = %f \n", x, y);
			ray = cast_ray(data->world->camera, x, y);
			color = color_at(data, ray);
			color_pixel(data, x, y, rgb(color));
		}
	}
	ft_printf("\rRendering: 100%%\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
							data->mlx_img->img_ptr, 200, 0);
}
