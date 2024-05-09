/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pars_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:22:55 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/08 11:10:54 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minirt.h"
# include "../include/tests.h"

/* Function to run tests for the is_digits function */
void test_is_digit(void) {
	printf("--- Test is_digit ---\n");
	// Test cases
	char *test_cases[] = {
		"12345",        // All digits
		"0",            // Single digit
		"123.456",      // Digits with a decimal point
		"12.34",        // Digits with a decimal point
		"123.abc",      // Digits with non-digit characters
		"abc",          // Non-digit characters only
		"",             // Empty string
		NULL            // Null pointer
	};

	// Expected results corresponding to the test cases
	bool expected_results[] = {
		true,   // All digits
		true,   // Single digit
		true,   // Digits with a decimal point
		true,   // Digits with a decimal point
		false,  // Digits with non-digit characters
		false,  // Non-digit characters only
		false,  // Empty string
		false   // Null pointer
	};

	// Iterate through the test cases
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		bool actual_result = is_digits(test_cases[i]);
		print_test_result(test_cases[i], expected_results[i], actual_result);
	}
}

/* Function to run tests for the is_identifier function */
void test_is_identifier(void) {
	printf("--- Test is_identifier ---\n");
	
	// Test cases
	char *test_cases[] = {
		"A",            // Single valid character (uppercase)
		"C",            // Single valid character (uppercase)
		"L",            // Single valid character (uppercase)
		"pl",           // Valid two-character identifier
		"sp",           // Valid two-character identifier
		"cy",           // Valid two-character identifier
		"abc",          // Invalid identifier (more than 2 characters)
		"123",          // Invalid identifier (digits only)
		"a1",           // Invalid identifier (alphanumeric)
		"",             // Empty string
		NULL            // Null pointer
	};

	// Expected results corresponding to the test cases
	bool expected_results[] = {
		true,   // Single valid character (uppercase)
		true,   // Single valid character (uppercase)
		true,   // Single valid character (uppercase)
		true,   // Valid two-character identifier
		true,   // Valid two-character identifier
		true,   // Valid two-character identifier
		false,  // Invalid identifier (more than 2 characters)
		false,  // Invalid identifier (digits only)
		false,  // Invalid identifier (alphanumeric)
		false,  // Empty string
		false   // Null pointer
	};

	// Iterate through the test cases
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		bool actual_result = is_identifier(test_cases[i]);
		print_test_result(test_cases[i], expected_results[i], actual_result);
	}
}

/* Function to run tests for the is_in_range function */
void test_is_in_range(void) {
	printf("--- Test is_in_range ---\n");
	
	// Test cases
	char *test_cases[] = {
		"5.0",          // Valid value within range
		"10.5",         // Valid value within range
		"15.7",         // Valid value within range
		"3.4",          // Valid value within range
		"20.0",         // Valid value within range
		"25.5",         // Valid value within range
		"0",            // Valid value at the lower bound
		"30",           // Valid value at the upper bound
		"-5",           // Invalid value below range
		"35",           // Invalid value above range
		"abc",          // Invalid value (non-numeric)
		"",             // Empty string
		NULL            // Null pointer
	};

	// Expected results corresponding to the test cases
	bool expected_results[] = {
		true,   // Valid value within range
		true,   // Valid value within range
		true,   // Valid value within range
		true,   // Valid value within range
		true,   // Valid value within range
		true,   // Valid value within range
		true,   // Valid value at the lower bound
		true,   // Valid value at the upper bound
		false,  // Invalid value below range
		false,  // Invalid value above range
		false,  // Invalid value (non-numeric)
		false,  // Empty string
		false   // Null pointer
	};

	// Define the range for the tests
	double min = 0.0;
	double max = 30.0;

	// Iterate through the test cases
	for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
		bool actual_result = is_in_range(min, max, test_cases[i]);
		print_test_result(test_cases[i], expected_results[i], actual_result);
	}
}
