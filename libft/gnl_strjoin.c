/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:32:27 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/11 18:42:19 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	frees input string (difference to ft_strjoin)	*/
char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*dst;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dst)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	dst[len1 + len2] = '\0';
	while (len2--)
		dst[len1 + len2] = s2[len2];
	while (len1--)
		dst[len1] = s1[len1];
	if (s1)
		free(s1);
	return (dst);
}
