/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:04:38 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 18:25:13 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	l;
	size_t	i;

	if (!s || !*s)
		return (NULL);
	l = ft_strlen(s);
	dst = (char *)(malloc((l + 1) * sizeof(char)));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		dst[i] = s[i];
		i++;
	}
	dst[l] = '\0';
	return (dst);
}
