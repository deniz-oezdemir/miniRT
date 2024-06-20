/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:52:31 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/20 15:19:30 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	handle_keyboard_input(int keysym, t_minirt *data)
{
	if (keysym == XK_q || keysym == XK_e
		|| keysym == XK_w || keysym == XK_s
		|| keysym == XK_a || keysym == XK_d)
		rotate(data, keysym);
	else if (keysym == XK_Escape)
		exit_program(data);
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	handle_mouse_input(int keysym, t_minirt *data)
{
	(void)data;
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	handle_close_button(t_minirt *data)
{
	exit_program(data);
	return (0);
}
