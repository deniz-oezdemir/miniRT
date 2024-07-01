/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/07/01 17:12:56 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	*data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nIncorrect arguments\n", 2);
		return (EXIT_FAILURE);
	}
	data = init_mlx();
	init_window(data);
	parse(data, argv[1]);
	render_scene(data);
	mlx_loop(data->mlx_ptr);
	exit_program(data, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
