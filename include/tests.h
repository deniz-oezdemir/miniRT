/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:42 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 18:35:24 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TESTS_H
# define MINIRT_TESTS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

/* Tests */
void	test_is_digit(void);
void	test_is_identifier(void);
void	test_is_in_range(void);
void	test_init_matrix(t_minirt *data);

/* Utils */
void    print_test_result(char *test_case, bool expected, bool actual);

#endif
