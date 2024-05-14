/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 16:37:23 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"

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
	printf("\nScene objects:\n"); //check
	print_list(data->objects);
	init_window(data);
	//mlx_loop(data->mlx_ptr);
	//destroy_window(data);
	gc_free(data->grbg);
	free(data);

	return (0);
}
