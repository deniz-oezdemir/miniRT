/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:58:44 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/13 13:05:43 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	remove_newline(char **str)
{
	char	*newline_pos;

	newline_pos = ft_strchr(*str, '\n');
	if (newline_pos != NULL)
		*newline_pos = '\0';
}