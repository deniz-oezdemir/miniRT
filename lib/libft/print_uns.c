/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:23:15 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/25 22:50:46 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_uns(unsigned int n)
{
	int	i;

	if (n > 9)
	{
		i = print_uns(n / 10);
		ft_putchar_fd((n % 10) + '0', 1);
		return (i + 1);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		return (1);
	}
}
