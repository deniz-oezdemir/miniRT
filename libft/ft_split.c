/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:18:54 by denizozd          #+#    #+#             */
/*   Updated: 2024/02/03 11:57:35 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			count++;
		while (*s && *s != sep)
			s++;
	}
	return (count);
}

static void	*free_arr_strs(char **arr_strs, size_t i)
{
	while (0 < i)
	{
		i--;
		free(arr_strs[i]);
	}
	free(arr_strs);
	return (NULL);
}

static char	**split(char const *s, char c, char **arr_strs)
{
	int		word_len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			arr_strs[i] = ft_substr(s, 0, word_len);
			if (arr_strs[i] == NULL)
				return (free_arr_strs(arr_strs, i));
			i++;
			s = s + word_len;
		}
	}
	arr_strs[i] = NULL;
	return (arr_strs);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_strs;

	arr_strs = NULL;
	if ((ft_count_words(s, c) > 0))
		arr_strs = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !arr_strs)
		return (0);
	arr_strs = split(s, c, arr_strs);
	return (arr_strs);
}
