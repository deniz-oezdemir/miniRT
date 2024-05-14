/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 13:59:18 by tiacovel         ###   ########.fr       */
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
	/* init_window(data);
	mlx_loop(data->mlx_ptr); */
	return (0);
}
