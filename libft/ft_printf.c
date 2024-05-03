/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:13:01 by denizozd          #+#    #+#             */
/*   Updated: 2023/11/25 23:11:55 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversion(const char *str, va_list args)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i = i + print_char(va_arg(args, int));
	else if (*str == 's')
		i = i + print_str(va_arg(args, char *));
	else if (*str == 'p')
		i = i + print_ptr(va_arg(args, unsigned long));
	else if (*str == 'd' || *str == 'i')
		i = i + print_int(va_arg(args, int));
	else if (*str == 'u')
		i = i + print_uns(va_arg(args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		i = i + print_hex(va_arg(args, unsigned int), *str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				i = i + print_char('%');
			else if (ft_strchr("cspdiuxX", *str))
				i = i + conversion(str, args);
		}
		else
			i = i + print_char(*str);
		str++;
	}
	va_end(args);
	return (i);
}
