/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:43:45 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/29 11:57:41 by tiacovel         ###   ########.fr       */
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

/* Clear the intersection list "xs" and free each node. */
void free_inter(void *content)
{
	t_inter *inter_content = (t_inter *)content;
	// Set the shape pointer to NULL but don't free the shape
	inter_content->shape = NULL;
}

void del_object(void *content) {
    t_shape *inter_content = (t_shape *)content;
    // Set the shape pointer to NULL but don't free the shape
    printf("Setting shape pointer %p to NULL\n", (void *)inter_content);
    // Free the t_inter struct itself
    free(inter_content);
	inter_content = NULL;
}

void del_light(void *content) {
    t_light *light_content = (t_light *)content;
    // Free the t_light struct itself
	printf("Setting light pointer %p to NULL\n", (void *)light_content);
    free(light_content);
}

void free_world(t_world *world) {
    if (!world) return;
    // Clear the objects list without freeing shapes
	if (world->objects != NULL) {
		world->object_nbr = 0;
		ft_lstclear(&world->objects, del_object);
	}
    	
    // Clear the lights list and free the light structs
	if (world->lights != NULL) {
		world->light_nbr = 0;
		ft_lstclear(&world->lights, del_light);
	}
    	
    // Free the camera if it is dynamically allocated
    if (world->camera != NULL) {
		printf("Free camera\n\n");
        free(world->camera);
        world->camera = NULL;
    }
    // Free the world struct itself
    //free(world);
}