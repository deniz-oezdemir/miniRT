/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:23:50 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 16:36:48 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"

void	destroy_window(t_minirt *data)
{
	printf("Quitting the program... \n");
	if (data->mlx_img->img_ptr != NULL)
		mlx_destroy_image(data->mlx_ptr, data->mlx_img->img_ptr);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr != NULL)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr != NULL)
		free(data->mlx_ptr);
	if (data->mlx_img != NULL)
		free(data->mlx_img);
	//free(data);
	//exit(EXIT_SUCCESS);
}
