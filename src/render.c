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
	return (comps);
}

t_color	shade_hit(t_world *world, t_comps comps)
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
	if (hit_inter.shape != NULL)
	{
		comps = prepare_computations(hit_inter, ray);
		color = shade_hit(data->world, comps);
	}
	ft_lstclear(&data->xs, free_inter);
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
		ft_printf("\rRendering: %d%%", (int)(y * 100.0 / IMG_HEIGHT));
		x = -1.0;
		while (++x < data->world->camera->hsize)
		{
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
