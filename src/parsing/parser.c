/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:08:26 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 14:14:00 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

	//loop
		//gnl
		//split
		// if A
			//parse_ambient_light(data); //atoi
		//else if C
			//parse_cylindr
		//else if ...
			///...
		//else
			//throw error: incorrect scene
		//free gnl, free split

static void	separate_by_comma(t_minirt *data, char *space_separated)
{
	char	**comma_separated;
	int		i;

	i = 0;
	comma_separated = ft_split(space_separated, ','); //free list scene at exit
	while(comma_separated[i])
		ft_lstadd_back(&(data->scene), ft_lstnew(comma_separated[i++]));
}

static void	file_to_scene_list(t_minirt *data)
{
	char	*line;
	char	**space_separated;
	char	**comma_separated;
	int		i;

	line = get_next_line(data->fd);
	if (!line || !ft_isprint(line[0]))
		printf("Error: file\n");
	remove_newline(&line);
	while (line && ft_isprint(line[0]))
	{
		space_separated = ft_split(line, ' '); //free list scene at exit
		i = -1;
		while (space_separated[++i])
		{
			if (ft_strchr(space_separated[i], ','))
				separate_by_comma(data, space_separated[i]);
			else
				ft_lstadd_back(&(data->scene), ft_lstnew(space_separated[i]));
		}
		line = get_next_line(data->fd);
		remove_newline(&line);
	}
	free(line);
}

static void	scene_list_to_structs_list(t_minirt *data, t_list **list)
{
	if (!ft_strncmp((*list)->content, "A", 1))
		parse_ambient_light(data, list);
	else if (!ft_strncmp((*list)->content, "C", 1))
		parse_camera(data, list);
	else if (!ft_strncmp((*list)->content, "L", 1))
		parse_light(data, list);
	else if (!ft_strncmp((*list)->content, "sp", 2))
		parse_sphere(data, list);
	else if (!ft_strncmp((*list)->content, "pl", 2))
		parse_plane(data, list);
	else if (!ft_strncmp((*list)->content, "cy", 2))
		parse_cylinder(data, list);
}

void parse(t_minirt *data, char *file_name)
{
	data->fd = open(file_name, O_RDONLY, 0);
	if (data->fd < 0)
		printf("Error: opening file\n");
	file_to_scene_list(data);
	close(data->fd);
	while(data->scene)
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
