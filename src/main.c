/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/08 18:08:36 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"

void print_node(void *data) {
    t_amblight *amblight = (t_amblight *)data;
    printf("Name: %s\n", amblight->name);
    printf("Intensity: %f\n", amblight->intensity);
    printf("RGB: (%d, %d, %d)\n", amblight->r, amblight->g, amblight->b);
	printf("\n");
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
	printf("\nScene objects:\n"); //check
	ft_lstiter(data->objects, print_node); //check

	/* init_window(data);
	mlx_loop(data->mlx_ptr); */
	return (0);
}
