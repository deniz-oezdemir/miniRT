/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:13:40 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/07 18:34:57 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"

/*
example input:
A 0.2 255,255,255
C -50,0,20 0,0,0
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255

to check:
- first in line is identifier A, C, L, pl,...
	- if A then
		- second in line is intensity [0.0-1.0]
		- third to fifth in line are RGB Colors[0-255]

if stuff missing - check identifier at certain spot after previous identifier
*/

/* Cheack weather a string represents a digit. */
bool	is_digits(char *s)
{
	int	i;

	if (s == NULL)
		return (false);
	if (*s == '\0')
		return (false);
	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (true);
	return (false);
}

/* Cheack weather a string represents an identifier for a scene object. */
bool	is_identifier(char *s)
{
	if (ft_strlen(s) == 1)
	{
		if (!ft_strncmp(s, "A", 1) || !ft_strncmp(s, "C", 1) || !ft_strncmp(s, "L", 1))
			return (true);
	}
	else if (ft_strlen(s) == 2)
	{
		if (!ft_strncmp(s, "pl", 2) || !ft_strncmp(s, "sp", 2) || !ft_strncmp(s, "cy", 2))
			return (true);
	}
	return (false);
}

/* Cheack weather a string is within a specified numeric range */
/* Used to check: intensity, normalized vector,light brigthness,... */
bool	is_in_range(double min, double max, char *s)
{
	double	n;

	if (!is_digits(s))
		return(false);
	n = atof(s);
	if (min <= n && max >= n)
		return (true);
	return (false);
}

/* Cheack weather a string represents a RGB color. */
bool	is_rgb(char *s)
{
	double	n;

	if (!is_digits(s))
		return(false);
	n = atof(s);
	if (0 <= n && 255 >= n)
		return (true);
	return (false);
}
