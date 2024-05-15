/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:23 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/15 13:26:38 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests.h"
# include "../include/minirt.h"

int main(void)
{
    t_minirt	*data;

    printf("--- Test init_ptr_matrix ---\n");
    data = init_mlx();

    // test_is_digit();
    // test_is_identifier();
    // test_is_in_range();
    test_init_ptr_matrix(data);
    return (0);
}
