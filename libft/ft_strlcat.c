/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:07 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/22 19:53:57 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	j = 0;
	while (dst[j] != '\0')
		j++;
	dst_len = j;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len + size);
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] != '\0' && i < size - dst_len - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst_len + src_len);
}
/* parameter size means the size of the destination string to be created */
/* appends string src to string dst */
/* appends at most size - dst_len - 1 */
/* NULL-terminates, unless size of destination is 0 or size < dst_len */
/* caution: undefined behavior if src and dst overlap */
