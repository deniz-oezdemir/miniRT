/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:28:53 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/17 15:03:45 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	else
	{
		i = 0;
		while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}
