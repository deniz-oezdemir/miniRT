# include "../include/minirt.h"

/* Clear the intersection list "xs" and free each node. */
void free_inter(void *content)
{
	t_inter *inter_content = (t_inter *)content;
	// Set the shape pointer to NULL but don't free the shape
	inter_content->shape = NULL;
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
	t_vec3 position;
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
	while (++y < IMG_HEIGHT)
	{
		printf("\rRendering: %d%%", (int)(y * 100.0 / IMG_HEIGHT));
		world_y = wall_size / 2 - pixel_size * y;
		x = -1.0;
		while (++x < IMG_WIDTH)
		{
			world_x = -wall_size / 2 + pixel_size * x;
			position = (t_vec3){world_x, world_y, wall_z, 1};
			ray = get_ray(data->world->camera->center, vec_norm(vec_sub(position, data->world->camera->center)));
			//printf("x = %f | y = %f | w_x = %f | w_y = %f\n", x, y, world_x, world_y);
			intersections(data, ray);
			hit_int = hit(data->xs);
			if (hit_int.shape != NULL)
			{
				//printf("hit\n");
				//color_pixel(data, x, y, rgb(hit_int.shape->sphere.color)); //function rgg: bitshifting not possible with doubles - will be replaced by lighting anyways
			}
			ft_lstclear(&data->xs, free_inter);
		}
	}
	printf("\rRendering: 100%%\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
 		data->mlx_img->img_ptr, 200, 0);
}
