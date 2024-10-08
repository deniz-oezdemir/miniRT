/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:08:26 by denizozd          #+#    #+#             */
/*   Updated: 2024/07/01 17:08:59 by denizozd         ###   ########.fr       */
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

static char	*gnl_gc_collect(t_minirt *data)
{
	char	*line;

	line = get_next_line(data->fd);
	gc_collect(data, line);
	return (line);
}

static void	file_to_scene_list(t_minirt *data)
{
	char	*line;
	char	**space_separated;
	int		i;

	line = gnl_gc_collect(data);
	if (!line)
		exit_program(data, FILE_COR_ERR);
	while (line)
	{
		while (!ft_isprint(line[0]))
			line = gnl_gc_collect(data);
		remove_newline(&line);
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
		line = gnl_gc_collect(data);
	}
}

static void	scene_list_to_structs_list(t_minirt *data, t_list **list)
{
	if (!ft_strncmp((*list)->content, "A", 1))
	{
		data->ambient_light_count++;
		parse_ambient_light(data, list);
	}
	else if (!ft_strncmp((*list)->content, "C", 1))
	{
		data->camera_count++;
		parse_camera(data, list);
	}
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
	if (data->ambient_light_count > 1 || data->camera_count > 1)
		exit_program(data, MULTIPLE_OBJS);
}

void	parse(t_minirt *data, char *file_name)
{
	char	*extension;

	data->fd = open(file_name, O_RDONLY, 0);
	if (data->fd < 0)
		exit_program(data, FILE_OPEN_ERR);
	extension = ft_strchr(file_name, '.');
	if (!extension || ft_strncmp(extension, ".rt", 3))
		exit_program(data, FILE_EXT_ERR);
	file_to_scene_list(data);
	close(data->fd);
	while (data->scene)
	{
		if (is_identifier(data->scene->content))
			scene_list_to_structs_list(data, &(data->scene));
		else
			exit_program(data, FILE_COR_ERR);
		data->scene = data->scene->next;
	}
}
