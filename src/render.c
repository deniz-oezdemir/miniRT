#include "../include/minirt.h"

/* Clear the intersection list "xs" and free each node. */
void free_inter(void *content)
{
	t_inter *inter_content = (t_inter *)content;
	// Set the shape pointer to NULL but don't free the shape
	inter_content->shape = NULL;
}

static int convert(double color)
{
	if (color > 1)
		color = 1;
	color *= 255 + 0.5;
	return (color);
}

static int rgb(t_color color)
{
	return (convert(color.r) << 16 | convert(color.g) << 8 | convert(color.b));
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

void render_scene(t_minirt *data)
{
	double x;
	double y;
	double world_x;
	double world_y;
	double wall_z = 10.0;
	double wall_size = 7.0;
	double pixel_size = wall_size / IMG_HEIGHT;
	t_vec3 pos;
	t_ray ray;
	t_inter hit_int;
	t_vec3 point;
	t_vec3 eyev;
	t_vec3 normalv;
	t_color color;

	print_instruction(data);
	color_background(data, BACKGROUND_COLOR);

	y = -1.0;
	printf("Start rendering...\n");

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
			intersections(data, ray);
			hit_int = hit(data->xs);
			if (hit_int.shape != NULL)
			{
				point = position(ray, hit_int.inter);
				eyev = vec_neg(ray.dir);
				normalv = normal_at(&(hit_int.shape->sphere), point);
				color = lighting(data, hit_int.shape, &((t_light *)data->world->lights->content)->pnt_light, point, eyev, normalv);
				color_pixel(data, x, y, rgb(color));
			}
			ft_lstclear(&data->xs, free_inter);
		}
	}
	printf("\rRendering: 100%%\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
							data->mlx_img->img_ptr, 200, 0);
}
