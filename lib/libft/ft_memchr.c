/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:12:34 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/19 20:22:10 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	f;
	size_t			i;

	str = (unsigned char *) s;
	f = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == f)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
