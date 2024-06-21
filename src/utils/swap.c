/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:58:44 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/21 09:44:56 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	swap(double *nbr1, double *nbr2)
{
	double	tmp;

	tmp = *nbr1;
	*nbr1 = *nbr2;
	*nbr2 = tmp;
}
