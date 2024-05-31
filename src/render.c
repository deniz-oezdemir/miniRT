# include "../include/minirt.h"

/* Clear the intersection list "xs" and free each node. */
void free_inter(void *content)
{
	t_inter *inter_content = (t_inter *)content;
	// Set the shape pointer to NULL but don't free the shape
	inter_content->shape = NULL;
}

static int	convert(float color)
{
	if (color > 1)
		color = 1;
	color *= 255 + 0.5;
	return (color);
}

static int	rgb(t_color color)
{
	return (
		convert(color.r) << 16
		| convert(color.g) << 8
		| convert(color.b)
	);
}
/*
static int	rgb(t_color color)
{
	return (
		color.r << 16
		| color.g << 8
		| color.b
	);
}*/

void    render_scene(t_minirt *data)
{
	double x;
	double y;
	double world_x;
	double world_y;
	double wall_z;
	double wall_size;
	double pixel_size;
	t_vec3 pos;
	t_ray ray;
	t_inter	hit_int;

	print_instruction(data);
	color_background(data, BACKGROUND_COLOR);

	wall_z = 10;
	wall_size = 7.0;
	pixel_size = wall_size / IMG_HEIGHT;
	//printf("pixel size: %f\n", pixel_size);
	y = -1.0;
	//printf("Start rendering...\n");

	//lighting
	t_vec3 light_position = (t_vec3){-10, 10, -10, 1};
	t_color light_color = (t_color){1, 1, 1};
	t_pointlight light = pointlight(light_position, light_color);

	while (++y < IMG_HEIGHT)
	{
		printf("\rRendering: %d%%", (int)(y * 100.0 / IMG_HEIGHT));
		world_y = wall_size / 2 - pixel_size * y;
		x = -1.0;
		while (++x < IMG_WIDTH)
		{
			world_x = -wall_size / 2 + pixel_size * x;
			pos = (t_vec3){world_x, world_y, wall_z, 1};
			ray = get_ray(data->world->camera->center, vec_norm(vec_sub(pos, data->world->camera->center)));
			//printf("x = %f | y = %f | w_x = %f | w_y = %f\n", x, y, world_x, world_y);
			intersections(data, ray);
			hit_int = hit(data->xs);
			if (hit_int.shape != NULL)
			{
				t_vec3 point = position(ray, hit_int.inter);
				t_vec3 eyev = vec_neg(ray.dir);
				t_vec3 normalv = normal_at(&(hit_int.shape->sphere), point);
				t_color color = lighting(hit_int.shape->material, light, point, eyev, normalv);
				//printf("hit\n");
				color_pixel(data, x, y, rgb(color));
			}
			ft_lstclear(&data->xs, free_inter);
		}
	}
	printf("\rRendering: 100%%\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
 		data->mlx_img->img_ptr, 200, 0);
}
