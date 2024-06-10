#include "../include/minirt.h"

t_comps	prepare_computations(t_inter inter, t_ray ray)
{
	t_comps	comps;

	comps.t = inter.inter;
	comps.shape = inter.shape;
	comps.point = position(ray, inter.inter);
	comps.eyev = vec_neg(ray.dir);
	comps.normalv = normal_at(&(inter.shape->sphere), comps.point);
	print_vec3(comps.normalv, "Normal at");
	comps.inside = false;
	if (vec_dot(comps.normalv, comps.eyev) < 0)
		comps.inside = true;
		// Add negation normalv
	return (comps);
}

t_color	shade_hit(t_world *world, t_comps comps)
{
	t_color		color;
	t_color		ambient;
	t_list		*lights;
	t_pntlight	*light;

	ambient =  mult_colors(comps.shape->color, world->ambient_light->light); // check if we need a material ambient ligh like in the other project
	color = (t_color){0, 0, 0};
	lights = world->lights;
	while (lights != NULL)
	{
		printf("OOOK 3\n");
		print_light(&((t_light *)lights->content)->pnt_light);
		light = &((t_light *)lights->content)->pnt_light;
		printf("OOOK 4\n");
		print_light(light);
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

	color = (t_color){0, 0, 0}; // Backgrounf color: PROBLEM here: should be dark grey but somehow it's white. Checked with the debugger, the problem should be in the function RGB
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
	printf("OOOK render scene\n");
	print_light(&((t_light *)data->world->lights->content)->pnt_light);
	//color_background(data, BACKGROUND_COLOR);
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
			print_color(color, "Color BG");
			printf("Color 01: %d", rgb(color));
			color_pixel(data, x, y, rgb(color));
		}
	}
	printf("\rRendering: 100%%\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
							data->mlx_img->img_ptr, 200, 0);
}
