/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/15 10:09:50 by denizozd         ###   ########.fr       */
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


	// TEST-matrix
	int **matrix = NULL;
	matrix = init_matrix(data, 7, 9);
	int i = 0, j = 0, k = 1;
	while (i < 7)
	{
		while(j < 9)
		{
			matrix[i][j] = k++;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0, j = 0;
	while (i < 7)
	{
		while(j < 9)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}


	// Start MLX window
	// init_window(data);
	// print_instruction(data);
	// render_scene(data);
	// mlx_loop(data->mlx_ptr);

	exit_program(data); //clean and exit
	return (0);
}
