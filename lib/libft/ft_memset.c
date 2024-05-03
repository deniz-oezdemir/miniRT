/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:08:23 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/20 15:36:16 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *)s;
	while (n > 0)
	{
		string[i] = c;
		i++;
		n--;
	}
	return (s);
}
/* writes n bytes of value c (converted to char) to string s */
