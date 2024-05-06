/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:08:26 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/06 15:11:53 by denizozd         ###   ########.fr       */
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

void	file_to_scene_list(t_minirt *data)
{
	char	*line;
	char	**space_separated;
	char	**comma_separated;
	int		i;

	line = get_next_line(data->fd);
	if (!line || !ft_isprint(line[0]))
		printf("Error: file\n");
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
	}
	free(line); //as last line is \0 for end of file
}

void	separate_by_comma(t_minirt *data, char *space_separated)
{
	char	**comma_separated;
	int		i;

	i = 0;
	comma_separated = ft_split(space_separated, ','); //free list scene at exit
	while(comma_separated[i])
		ft_lstadd_back(&(data->scene), ft_lstnew(comma_separated[i++]));
}

void	scene_list_to_structs_list(t_minirt *data)
{
	while(data->scene)
	{
		if (ft_strncmp(data->scene->content, "A", 1))
			parse_ambient_light(data, data->scene);
		else
			data->scene = data->scene->next;
	}
}


