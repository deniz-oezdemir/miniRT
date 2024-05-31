/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/31 23:23:14 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"

/* Render the scene */
/* for test only */
/* void	render_scene(t_minirt *data)
{
	print_instruction(data);
	color_background(data, BACKGROUND_COLOR);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img->img_ptr, 200, 0);
} */

int	main(int argc, char **argv)
{
	t_minirt	*data;

	if (argc != 2)
	{
		printf("ERROR: please check input arguments!\n");
		return (EXIT_FAILURE);
	}
	data = init_mlx();
	parse(data, argv[1]);
	//Print scene objects attributes
	print_scene_objects(data->world);

	// Start MLX window
	init_window(data);
	render_scene(data);
	mlx_loop(data->mlx_ptr);

	//test_light(data);

	//casting missing to test with input file
	/*printf("\nc0\n");
	t_shape *sphere = ((t_world *)(data->world))->objects->next->next->content;
	printf("\nc1\n");
	print_material(sphere->material);*/

	exit_program(data); //clean and exit
	return (EXIT_SUCCESS);
}
