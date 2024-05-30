# include "../include/minirt.h"

void    render_scene(t_minirt *data)
{
	int x;
	int y;
	int world_x;
	int world_y;
	int pixel_size;
	t_vec3 position;
	t_ray ray;

	print_instruction(data);
	color_background(data, BACKGROUND_COLOR);

	pixel_size = 110 / IMG_HEIGHT; //7 to be modified accordingly
	y = -1;
	printf("Start rendering...\n");
	while (++y < IMG_HEIGHT)
	{
		ft_printf("\rRendering: %d%%\n", (int)(y * 100.0 / IMG_HEIGHT));
		world_y = IMG_HEIGHT / 2 - pixel_size * y;
		x = -1;
		printf(" y= %d\n", world_y);
		while (++x < IMG_WIDTH)
		{
			
			world_x = -IMG_HEIGHT / 2 + pixel_size * x;
			printf(" x= %d\n", world_x);
			position = (t_vec3){world_x, world_y, 10, 1}; //check 10
			ray = get_ray(data->world->camera->center, vec_norm(vec_sub(position, data->world->camera->center)));
			print_vec3(vec_norm(vec_sub(position, data->world->camera->center)), "nrom vec");
			intersections(data, ray);
			if (hit(data->xs).shape != NULL)
			{
				printf("hit\n");
				color_pixel(data, x, y, 0xffffff);
			}
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
 		data->mlx_img->img_ptr, 200, 0);
}