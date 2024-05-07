/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:13:40 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/07 15:48:24 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

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


bool	is_identifier(char *s)
{
	if (ft_strlen(s) == 1)
		if (!ft_strncmp(s, "A", 1) || !ft_strncmp(s, "C", 1) || !ft_strncmp(s, "L", 1))
			return (1);
	else if (ft_strlen(s) == 2)
		if (!ft_strncmp(s, "pl", 2) || !ft_strncmp(s, "sp", 2) || !ft_strncmp(s, "cy", 2))
			return (1);
	return (0);
}

/* is range: intensity, normalized vector,light brigthness,... */
bool is_in_range(double min, double max, char *s)
{
	double	n;

	n = atof(s);
	if (min <= n && max >= n)
		return (1);
	return (0);
}

bool	is_rgb(char *s)
{
	double	n;

//is digits

	n = atof(s);
	if (0 <= n && 255 >= n)
		return (1);
	return (0);
}

bool	is_digits(char *s)
{
	int	i;

	i = 0;
	while(ft_isdigit(s[i]))
		i++;

	if dot
	while isdigits

	if (i == ft_strlen(s))
		return (1);
	return (0);
}
