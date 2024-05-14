/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:50:59 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/14 14:57:50 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//delete file if not needed

# include "../../include/minirt.h"

static int	get_len(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len += 1;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*fill_the_array(int len, char *dest, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		dest[0] = '-';
		n = n * (-1);
		i = 1;
	}
	dest[len] = '\0';
	len -= 1;
	while (len >= i)
	{
		dest[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (dest);
}

char	*gc_itoa(t_minirt *data, int n)
{
	char	*dest;
	size_t	len;
	long	num;

	if (n == -2147483648)
		return (dest = gc_strdup(data, "-2147483648"));
	if (n == 0)
		return (dest = gc_strdup(data, "0"));
	num = n;
	len = get_len(num);
	dest = gc_get(data, len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	dest = fill_the_array(len, dest, num);
	return (dest);
}
