/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:27:25 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/07 15:25:52 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// adding to libft allowed?
double	atof(const char *str)
{
	int		i;
	int		b; //base
	int		s; //sign
	double	v; //value

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	s = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s = -1;
	v = 0;
	while (ft_isdigit(str[i]))
		v = v * 10 + (str[i++] - '0');
	if (str[i] != '.')
		return ((double)v * s);
	b = 10;
	while (ft_isdigit(str[++i]))
	{
		v = v + (double)(str[i] - '0') / b;
		b = b * 10;
	}
	return ((double)v * s);
}


