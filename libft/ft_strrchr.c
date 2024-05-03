/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:02:56 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/20 15:56:43 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	f;

	f = (char) c;
	i = 0;
	while (s[i])
		i++;
	if (f == '\0')
		return ((char *) &s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == f)
			return ((char *) &s[i]);
	}
	return (NULL);
}
/* locates last occurence of char c in string s */
/* caution: c might be the NULL-terminator */
