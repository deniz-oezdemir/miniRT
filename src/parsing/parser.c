/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:08:26 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/27 16:01:09 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	separate_by_comma(t_minirt *data, char *space_separated)
{
	char	**comma_separated;
	int		i;

	i = 0;
	comma_separated = gc_split(data, space_separated, ',');
	while (comma_separated[i])
		ft_lstadd_back(&(data->scene), gc_lstnew(data, comma_separated[i++]));
}

static void	file_to_scene_list(t_minirt *data)
{
	char	*line;
	char	**space_separated;
	int		i;

	line = get_next_line(data->fd);
	gc_collect(data, line);
	if (!line || !ft_isprint(line[0]))
		printf("Error: file\n");
	remove_newline(&line);
	while (line && ft_isprint(line[0]))
	{
		space_separated = gc_split(data, line, ' ');
		i = -1;
		while (space_separated[++i])
		{
			if (ft_strchr(space_separated[i], ','))
				separate_by_comma(data, space_separated[i]);
			else
				ft_lstadd_back(&(data->scene), gc_lstnew(data,
						space_separated[i]));
		}
		line = get_next_line(data->fd);
		gc_collect(data, line);
		remove_newline(&line);
	}
}

static void	scene_list_to_structs_list(t_minirt *data, t_list **list)
{
	if (!ft_strncmp((*list)->content, "A", 1))
		parse_ambient_light(data, list);
	else if (!ft_strncmp((*list)->content, "C", 1))
		parse_camera(data, list);
	else if (!ft_strncmp((*list)->content, "L", 1))
		parse_pnt_light(data, list);
	else if (!ft_strncmp((*list)->content, "sp", 2))
		parse_sphere(data, list);
	else if (!ft_strncmp((*list)->content, "pl", 2))
		parse_plane(data, list);
	else if (!ft_strncmp((*list)->content, "cy", 2))
		parse_cylinder(data, list);
	else if (!ft_strncmp((*list)->content, "cn", 2))
		parse_cone(data, list);
}

void	parse(t_minirt *data, char *file_name)
{
	char *extension;

	extension = ft_strchr(file_name, '.');
	if (!extension || ft_strncmp(extension, ".rt", 3))
		printf("Error: wrong file extension\n"); //exit
	data->fd = open(file_name, O_RDONLY, 0);
	if (data->fd < 0)
		printf("Error: opening file\n"); //exit?
	file_to_scene_list(data);
	close(data->fd);
	while (data->scene)
	{
		if (is_identifier(data->scene->content))
			scene_list_to_structs_list(data, &(data->scene));
		else
		{
			printf("TODO: implement exit in case of parsing error\n");
			break ;
		}
		data->scene = data->scene->next;
	}
}
