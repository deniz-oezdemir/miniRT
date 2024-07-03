/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:26:42 by tiacovel          #+#    #+#             */
/*   Updated: 2024/07/03 15:35:51 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//DO NOT SUMBIT!

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
void	test_determinant_2x2(t_minirt *data);
void	test_sub_mtx(t_minirt *data);
void	test_mtx_minor(t_minirt *data);
void	test_mtx_cofactor(t_minirt *data);
void	test_mtx_determinant(t_minirt *data);
void	test_mtx_determinant_4x4(t_minirt *data);
void	test_rays();
void	test_inter(t_minirt *data);
void	test_inter_2(t_minirt *data);
void    test_transform_view(t_minirt *data);
void    test_light(t_minirt *data);


/* Utils */
void	print_test_result(char *test_case, bool expected, bool actual);
void	free_inter(void *content);
void	free_world(t_world *world);

#endif
