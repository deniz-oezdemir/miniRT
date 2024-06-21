/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:32:16 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/21 09:32:39 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_material	default_material(void)
{
	return ((t_material){.diffuse = 0.9, .specular = 0.9, .shininess = 200.0});
}
