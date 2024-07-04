/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/07/04 16:34:03 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	*data;

	data = init_minirt();
	init_window(data);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nIncorrect arguments\n", 2);
		exit_program(data, EXIT_FAILURE);
	}
	parse(data, argv[1]);
	render_scene(data);
	mlx_loop(data->mlx_ptr);
	exit_program(data, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
