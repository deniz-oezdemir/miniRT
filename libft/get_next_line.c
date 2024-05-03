/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:27:50 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 18:34:02 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The extract_excess function takes a line pointer as input,
	searches for a newline character, and, if found,
	duplicates the excess characters beyond the newline,
	truncates the original line one after its newline character,
	and returns the duplicated excess or NULL if no newline is present.*/
char	*extract_excess(char *line)
{
	char	*eol;
	char	*excess;

	eol = ft_strchr(line, '\n');
	if (eol == NULL)
		return (NULL);
	eol++;
	excess = ft_strdup(eol);
	*eol = '\0';
	return (excess);
}

/*The read_buffer function takes a line pointer and a file descriptor,
	reads data into a static buffer from the file until a newline
	character is found,	dynamically growing the line,
	and returns the updated line or NULL in case of errors.*/
/*Caution: If buf is not declared as static or allocated dynamically,
	there may be a stack overflow for a high BUFFER_SIZE.*/
char	*read_buffer(char *line, int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		nb;

	while (!ft_strchr(line, '\n'))
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb == 0)
			break ;
		if (nb == -1)
		{
			free(line);
			return (NULL);
		}
		buf[nb] = '\0';
		line = gnl_strjoin(line, buf);
	}
	return (line);
}

/*The get_next_line function reads a line from a file descriptor,
	utilizing the read_buffer function to get the line,
	and then uses the extract_excess function to handle any extra
	characters read beyond the newline character,
	returning the line read or NULL in case of errors.*/
char	*get_next_line(int fd)
{
	static char	*excess;
	char		*line;

	line = read_buffer(excess, fd);
	excess = extract_excess(line);
	return (line);
}
