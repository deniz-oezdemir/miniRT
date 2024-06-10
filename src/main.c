/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/10 16:31:00 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

/* Render the scene */
/* for test only */
/* void	render_scene(t_minirt *data)
{
	print_instruction(data);
	color_background(data, BACKGROUND_COLOR);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img->img_ptr, 200, 0);
} */

int main(int argc, char **argv)
{
	t_minirt *data;

	if (argc != 2)
	{
		printf("ERROR: please check input arguments!\n");
		return (EXIT_FAILURE);
	}
	data = init_mlx();
	parse(data, argv[1]);
	// t_pntlight *light = ((t_pntlight *)data->world->lights->content);

	// Print scene objects attributes
	// print_scene_objects(data->world);
	printf("OOOK 2\n");
	print_light(&((t_light *)data->world->lights->content)->pnt_light);
	
	// Start MLX window
	init_window(data);
	render_scene(data);
	mlx_loop(data->mlx_ptr);

	printf("OOOK END\n");
	print_light(&((t_light *)data->world->lights->content)->pnt_light);

	// test_light(data);
	exit_program(data); //clean and exit
	return (EXIT_SUCCESS);
}
