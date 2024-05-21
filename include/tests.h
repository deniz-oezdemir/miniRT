/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:42 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/21 16:33:55 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TESTS_H
# define MINIRT_TESTS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "minirt.h"

/* Tests */
void	test_is_digit(void);
void	test_is_identifier(void);
void	test_is_in_range(void);
void	test_vec_ops(void);
void	test_mtx_ops(void);
void	test_mtx_trans(void);
void	test_determinant_2x2(void);
void	test_sub_mtx(void);
void	test_mtx_minor(void);
void	test_mtx_cofactor(void);
void	test_mtx_determinant(void);
void	test_mtx_determinant_4x4(void);

/* Utils */
void    print_test_result(char *test_case, bool expected, bool actual);

#endif
