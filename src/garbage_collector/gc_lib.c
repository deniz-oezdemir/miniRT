/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:10:07 by ecarlier          #+#    #+#             */
/*   Updated: 2024/06/21 08:47:26 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/* custom libft functions with gc_get replacing malloc and ft_calloc */

char	*gc_strdup(t_minirt *data, const char *s)
{
	size_t	len;
	size_t	i;
	char	*dest;

	i = 0;
	len = ft_strlen(s) + 1;
	dest = gc_get(data, len, sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gc_substr(t_minirt *data, char const *s, unsigned int start,
		size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (ft_strlen(s) < start)
		return (gc_strdup(data, ""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dest = gc_get(data, len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_list	*gc_lstnew(t_minirt *data, void *content)
{
	t_list	*new;

	new = gc_get(data, 1, sizeof(t_list));
	if (new == NULL)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
