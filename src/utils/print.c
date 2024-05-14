/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:53:30 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/14 14:13:13 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"
// DO NOT SUBMIT !!!
// Print function for each type of object
void print_amblight(t_amblight *obj)
{
	printf("Name: %s\n", obj->name);
	printf("Intensity: %lf\n", obj->intensity);
	printf("RGB: (%d, %d, %d)\n", obj->r, obj->g, obj->b);
}

void print_camera(t_camera *obj)
{
	printf("Name: %s\n", obj->name);
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->x, obj->y, obj->z);
	printf("View direction: (%d, %d, %d)\n", obj->xv, obj->yv, obj->zv);
	printf("Field of View: %d\n", obj->fov);
}

void print_light(t_light *obj)
{
	printf("Name: %s\n", obj->name);
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->x, obj->y, obj->z);
	printf("Intensity: %lf\n", obj->intensity);
	printf("RGB: (%d, %d, %d)\n", obj->r, obj->g, obj->b);
}

void print_sphere(t_sphere *obj)
{
	printf("Name: %s\n", obj->name);
	printf("Center: (%lf, %lf, %lf)\n", obj->x, obj->y, obj->z);
	printf("Diameter: %lf\n", obj->diameter);
	printf("RGB: (%d, %d, %d)\n", obj->r, obj->g, obj->b);
}

void print_plane(t_plane *obj)
{
	printf("Name: %s\n", obj->name);
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->x, obj->y, obj->z);
	printf("Normal: (%d, %d, %d)\n", obj->xv, obj->yv, obj->zv);
	printf("RGB: (%d, %d, %d)\n", obj->r, obj->g, obj->b);
}

void print_cylinder(t_cylinder *obj)
{
	printf("Name: %s\n", obj->name);
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->x, obj->y, obj->z);
	printf("Axis direction: (%d, %d, %d)\n", obj->xv, obj->yv, obj->zv);
	printf("Diameter: %lf\n", obj->diameter);
	printf("Height: %lf\n", obj->height);
	printf("RGB: (%d, %d, %d)\n", obj->r, obj->g, obj->b);
}


void print_list(t_list *head) {
	t_list *current = head;

	while (current != NULL) {
		if (current->content != NULL) {
			if (!strncmp(((t_amblight *)current->content)->name, "A", 1)  ) {
				print_amblight((t_amblight *)current->content);
			} else if (!strncmp(((t_camera *)current->content)->name, "C", 1)) {
				print_camera((t_camera *)current->content);
			} else if (!strncmp(((t_light *)current->content)->name, "L", 1)) {
				print_light((t_light *)current->content);
			} else if (!strncmp(((t_sphere *)current->content)->name, "sp", 2)) {
				print_sphere((t_sphere *)current->content);
			} else if (!strncmp(((t_plane *)current->content)->name, "pl", 2)) {
				print_plane((t_plane *)current->content);
			} else if (!strncmp(((t_cylinder *)current->content)->name, "cy", 2)) {
				print_cylinder((t_cylinder *)current->content);
			}
			// Add more else if clauses for other struct types...
		}
		current = current->next;
	}
}