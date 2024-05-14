/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 14:36:40 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"

/* Render the scene */
/* for test only */
void	render_scene(t_minirt *data)
{
	color_background(data, BACKGROUND_COLOR);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, 
		data->mlx_img->img_ptr, 200, 0);
}

int	main(int argc, char **argv)
{
	t_minirt	*data;

	if (argc != 2)
	{
		printf("ERROR: please check input arguments!");
		return (EXIT_FAILURE);
	}
	data = init_mlx();

	parse(data, argv[1]);
	// Print scene objects attributes
	printf("\nScene objects:\n"); //check
	print_list(data->objects);

	// Start MLX window
	// init_window(data);
	// print_instruction(data);
	// render_scene(data);
	// mlx_loop(data->mlx_ptr);
	return (0);
}
