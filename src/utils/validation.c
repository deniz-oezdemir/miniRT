/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:13:40 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:42:07 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* Cheack wether a string represents a digit. */
/* Validate only positive values. */
bool	is_digits(char *s)
{
	size_t	i;

	if (s == NULL)
		return (false);
	if (*s == '\0')
		return (false);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
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
		if (!ft_strncmp(s, "A", 1) || !ft_strncmp(s, "C", 1) || !ft_strncmp(s,
				"L", 1))
			return (true);
	}
	else if (ft_strlen(s) == 2)
	{
		if (!ft_strncmp(s, "pl", 2) || !ft_strncmp(s, "sp", 2) || !ft_strncmp(s,
				"cy", 2) || !ft_strncmp(s, "cn", 2))
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
		return (false);
	n = atof(s);
	if (min <= n && max >= n)
		return (true);
	return (false);
}
