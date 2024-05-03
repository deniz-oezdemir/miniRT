/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:08:07 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/25 22:54:40 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_ptr(unsigned long ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr / 16;
	}
	return (i);
}

static int	print_ptrhex(unsigned long ptr)
{
	if (ptr >= 16)
	{
		print_ptrhex(ptr / 16);
		print_ptrhex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + '0', 1);
		else
			ft_putchar_fd(ptr + 'a' - 10, 1);
	}
	return (count_ptr(ptr));
}

int	print_ptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		len = 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		len = 2 + print_ptrhex(ptr);
	}
	return (len);
}
