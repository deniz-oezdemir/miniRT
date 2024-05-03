/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/03 17:09:51 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	*data;

	/* if (argc != 2)
	{
		//ft_printf("ERROR: please check input arguments!");
		return (EXIT_FAILURE);
	} */
	data = init_mlx();

	data->fd = open(argv[1], O_RDONLY, 0);
	if (data->fd < 0)
		printf("Error: opening file"); //add: close fd, free data
	parse_objects(data);

	init_window(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
