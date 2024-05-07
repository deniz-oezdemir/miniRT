/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:57:56 by denizozd          #+#    #+#             */
/*   Updated: 2024/05/07 15:45:15 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_amblight{
	char	*name;
	double	intensity;
	int		r;
	int		g;
	int		b;
}	t_amblight;

typedef struct s_cylinder{
	char	*name;
	double	x;
	double	y;
	double	z;
	double	xv;
	double	yv;
	double	zv;
	double	diameter;
	double	height;
	int		r;
	int		g;
	int		b;
}	t_cylinder;
