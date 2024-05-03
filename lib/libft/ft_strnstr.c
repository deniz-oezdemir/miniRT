/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:01 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/13 14:49:07 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;

	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	l = ft_strlen(little);
	while (*big && l <= len)
	{
		if (*big == *little && ft_strncmp(big, little, l) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
