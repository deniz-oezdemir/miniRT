#include "../include/minirt.h"

t_comps	prepare_computations(t_inter inter, t_ray ray)
{
	t_comps	comps;

	comps.t = inter.inter;
	comps.shape = inter.shape;
	comps.point = position(ray, inter.inter);
	comps.eyev = vec_neg(ray.dir);
	comps.normalv = normal_at(&(inter.shape->sphere), comps.point);
	comps.inside = false;
	if (vec_dot(comps.normalv, comps.eyev) < 0)
		comps.inside = true;
	return (comps);
}

t_color	shade_hit(t_world *world, t_comps comps)
{
	t_color		color;
	t_list		*lights;
	t_pntlight	*light;

	color =  mult_colors(comps.shape->color, world->ambient_light->light);
	lights = world->lights;
	while (lights != NULL)
	{
		printf("check\n");
		light = (t_pntlight *)lights->content;
		color = color_add(color, lighting(comps, world->ambient_light, light));
		lights = lights->next;
	}
	return (color);
}

t_color	color_at(t_minirt *data, t_ray ray)
{
	t_inter	hit_inter;
	t_comps	comps;
	t_color	color;

	color = (t_color){0, 0, 0};
	intersections(data, ray);
	hit_inter = hit(data->xs);
	if (hit_inter.shape != NULL)
	{
		printf("hit: %f\n", hit_inter.inter);
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
	color_background(data, BACKGROUND_COLOR);
	y = -1.0;
	printf("Start rendering...\n");

	while (++y < data->world->camera->vsize)
	{
		printf("\rRendering: %d%%", (int)(y * 100.0 / IMG_HEIGHT));
		x = -1.0;
		while (++x < data->world->camera->hsize)
		{
			printf("x = %f | y = %f \n", x, y);
			ray = cast_ray(data->world->camera, x, y);
			// print_vec3(ray.origin, "vec origin");
			// print_vec3(ray.dir, "vec dir");
			color = color_at(data, ray);
			color_pixel(data, x, y, rgb(color));
		}
	}
	printf("\rRendering: 100%%\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
							data->mlx_img->img_ptr, 200, 0);
}
