/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:43:45 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/07 18:46:07 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests.h"

/* Function to compare expected and actual results and print the test result */
void print_test_result(char *test_case, bool expected, bool actual) {
	if (test_case != NULL) {
		printf("%s: %s\n", test_case, expected == actual ? "Passed" : "Failed");
	} else {
		printf("NULL : %s\n", expected == actual ? "Passed" : "Failed");
	}
}