/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:53 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 15:58:22 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

static bool	validate_amblight(t_amblight *amblight)
{
	if ((amblight->intensity < 0)
		|| (amblight->r < 0) || (amblight->g < 0) || (amblight->b < 0))
		return (false);
	return (true);
}

void	parse_ambient_light(t_minirt *data, t_list **input_lst)
{
	t_amblight	*amblight;

	amblight = ft_calloc(1, sizeof(t_amblight));
	if (!amblight)
		printf("Error: allocation failed\n");
	amblight->name = (*input_lst)->content;
	amblight->intensity = check_intensity(get_nth_content(*input_lst, 1));
	amblight->r = check_rgb(get_nth_content(*input_lst, 2));
	amblight->g = check_rgb(get_nth_content(*input_lst, 3));
	amblight->b = check_rgb(get_nth_content(*input_lst, 4));
	if (!validate_amblight(amblight))
		return (pars_error(AMB_LIGHT_ERR));
	ft_lstadd_back(&(data->objects), ft_lstnew(amblight));
	move_to_nth_node(input_lst, 4);
	printf("Ambient light OK\n");
}
