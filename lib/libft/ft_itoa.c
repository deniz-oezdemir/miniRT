/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:42:40 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/19 20:16:26 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_fill_nmbrs(int len, int position, int n, char *str)
{
	while (len > position)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		position;
	char	*str;

	position = 0;
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == -2147483648)
	{
		free(str);
		return (ft_strdup("-2147483648"));
	}
	if (n < 0)
	{
		str[position] = '-';
		n = -n;
		position++;
	}
	ft_fill_nmbrs(len, position, n, str);
	str[len] = '\0';
	return (str);
}
