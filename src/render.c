# include "../include/minirt.h"

void    render_scene(t_minirt *data)
{
	int x;
	int y;
	double world_x;
	double world_y;
	double pixel_size;
	t_vec3 position;
	t_ray ray;

	print_instruction(data);
	color_background(data, BACKGROUND_COLOR);

	pixel_size = 0.6; //7 to be modified accordingly
	printf("pixel size: %f\n", pixel_size);
	y = -1;
	printf("Start rendering...\n");
	while (++y < IMG_HEIGHT)
	{
		ft_printf("\rRendering: %d%%\n", (int)(y * 300.0 / IMG_HEIGHT));
		world_y = IMG_HEIGHT / 2 - pixel_size * y;
		x = -1;
		while (++x < IMG_WIDTH)
		{

			world_x = -IMG_HEIGHT / 2 + pixel_size * x;
			position = (t_vec3){world_x, world_y, 5, 1}; //check 10
			ray = get_ray(data->world->camera->center, vec_norm(vec_sub(position, data->world->camera->center)));
			printf("x = %d | y = %d | w_x = %f | w_y = %f\n", x, y, world_x, world_y);
			//print_vec3(vec_norm(vec_sub(position, data->world->camera->center)), "norm vec");
			intersections(data, ray);
			if (hit(data->xs).shape != NULL)
			{
				printf("hit\n");
				color_pixel(data, x, y, 0xffffff);
			}
			else
				color_pixel(data, x, y, BACKGROUND_COLOR);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
 		data->mlx_img->img_ptr, 200, 0);
}
