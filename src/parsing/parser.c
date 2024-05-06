/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:08:26 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/06 12:59:36 by denizozd         ###   ########.fr       */
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

void	file_to_list(t_minirt *data)
{
	char	*line;
	char	**space_seperated;
	char	**comma_seperated;
	int		i;

	line = get_next_line(data->fd);
	if (!line || !ft_isprint(line[0]))
		printf("Error: file\n");
	while (line && ft_isprint(line[0]))
	{
		space_seperated = ft_split(line, ' '); //free list objects at exit
		i = -1;
		while (space_seperated[++i])
		{
			if (ft_strchr(space_seperated[i], ','))
				seperate_by_comma(data, space_seperated[i]);
			else
				ft_lstadd_back(&(data->objects), ft_lstnew(space_seperated[i]));
		}
		line = get_next_line(data->fd);
	}
	free(line); //as last line is \0 for end of file
}

void	seperate_by_comma(t_minirt *data, char *space_seperated)
{
	char	**comma_seperated;
	int		i;

	i = 0;
	comma_seperated = ft_split(space_seperated, ','); //free list objects at exit
	while(comma_seperated[i])
		ft_lstadd_back(&(data->objects), ft_lstnew(comma_seperated[i++]));
}


