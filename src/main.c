/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:05:31 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/07 14:08:57 by denizozd         ###   ########.fr       */
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
		printf("Error: opening file\n"); //add: close fd, free data

	file_to_scene_list(data);
	close(data->fd); //change if file needed elsewhere
	printf("scene list's contents:\n"); //check
	ft_lstiter(data->scene, printf); //check

	scene_list_to_structs_list(data);
	t_amblight *al = (t_amblight *)((t_list *)(data->objects)->content); //check
	printf("\namblight:\nname: %s - intensity: %f - r: %d - g: %d - b: %d\n", al->name, al->intensity, al->r, al->g, al->b); //check

	//init_window(data);
	//mlx_loop(data->mlx_ptr);
	return (0);
}
