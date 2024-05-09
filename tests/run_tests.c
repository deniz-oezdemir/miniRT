/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:23 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/08 11:11:15 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests.h"

int main(void)
{
    test_is_digit();
    test_is_identifier();
    test_is_in_range();
    return (0);
}
