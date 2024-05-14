/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:10:07 by ecarlier          #+#    #+#             */
/*   Updated: 2024/05/14 14:57:53 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//delete file if not needed

# include "../../include/minirt.h"

/* custom libft functions with gc_get instead of malloc or ft_calloc*/

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

char	*gc_strjoin(t_minirt *data, char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = gc_get(data, sizeof(char), len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(dest, s2, len);
	return (dest);
}
