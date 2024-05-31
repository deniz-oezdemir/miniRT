/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:53:30 by tiacovel          #+#    #+#             */
/*   Updated: 2024/05/31 21:55:27 by denizozd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/minirt.h"
// DO NOT SUBMIT !!!
// Print function for each type of object
void print_amblight(t_amblight *obj)
{
	printf("Name: Ambient light\n");
	printf("Intensity: %lf\n", obj->intensity);
	printf("RGB: (%f, %f, %f)\n", obj->color.r, obj->color.g, obj->color.b);
}

void print_camera(t_camera *obj)
{
	printf("Name: Camera\n");
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->center.x, obj->center.y, obj->center.z);
	printf("View direction: (%f, %f, %f)\n", obj->dir.x, obj->dir.y, obj->dir.z);
	printf("Field of View: %d\n", obj->fov);
}

void print_light(t_pntlight *obj)
{
	printf("Name: Point light\n");
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->center.x, obj->center.y, obj->center.z);
	printf("Intensity: %lf\n", obj->intensity);
	printf("RGB: (%f, %f, %f)\n", obj->color.r, obj->color.g, obj->color.b);
}

void print_sphere(t_sphere *obj)
{
	printf("Name: Sphere\n");
	printf("Center: (%lf, %lf, %lf)\n", obj->center.x, obj->center.y, obj->center.z);
	printf("Diameter: %lf\n", obj->diameter);
	printf("RGB: (%f, %f, %f)\n", obj->color.r, obj->color.g, obj->color.b);
}

void print_plane(t_plane *obj)
{
	printf("Name: Plane\n");
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->center.x, obj->center.y, obj->center.z);
	printf("Normal: (%f, %f, %f)\n", obj->dir.x, obj->dir.y, obj->dir.z);
	printf("RGB: (%f, %f, %f)\n", obj->color.r, obj->color.g, obj->color.b);
}

void print_cylinder(t_cylinder *obj)
{
	printf("Name: Cylinder\n");
	printf("Coordinates: (%lf, %lf, %lf)\n", obj->center.x, obj->center.y, obj->center.z);
	printf("Axis direction: (%f, %f, %f)\n", obj->dir.x, obj->dir.y, obj->dir.z);
	printf("Diameter: %lf\n", obj->diameter);
	printf("Height: %lf\n", obj->height);
	printf("RGB: (%f, %f, %f)\n", obj->color.r, obj->color.g, obj->color.b);
}


void print_scene_objects(t_world *world)
{
	t_list	*shapes = world->objects;
	t_list	*lights = world->lights;

	printf("\n*** Scene objects ***\n\n");
	if (world->camera != NULL)
		print_camera(world->camera);
	printf(" \nShapes:\n");
	if (shapes == NULL)
		printf("Empty Shapes list!\n");
	while (shapes != NULL)
	{
		if (shapes->content == NULL)
			continue;
		printf("Shape ID: %d\n", ((t_shape *)shapes->content)->name);
		if (((t_shape *)shapes->content)->name  == SPHERE)
			print_sphere(&((t_shape *)shapes->content)->sphere);
		else if (((t_shape *)shapes->content)->name  == PLANE)
			print_plane(&((t_shape *)shapes->content)->plane);
		else if (((t_shape *)shapes->content)->name  == CYLINDER)
			print_cylinder(&((t_shape *)shapes->content)->cylinder);
		printf("\n");
		shapes = shapes->next;
	}
	printf(" \nLights:\n");
	if (lights == NULL)
		printf("Empty Lights list!\n");
	while (lights != NULL)
	{
		if (lights->content == NULL)
			continue ;
		if (((t_light *)lights->content)->name  == AMB_LIGHT)
			print_amblight(&((t_light *)lights->content)->amb_light);
		else if (((t_light *)lights->content)->name  == PNT_LIGHT)
			print_light(&((t_light *)lights->content)->pnt_light);
		printf("\n");
		lights = lights->next;
	}
}

void print_vec3(t_vec3 v, char* label)
{
	int precision = 8;
	printf("%s:	(%.*f,	%.*f,	%.*f,	%f)\n", label, precision, v.x, precision, v.y, precision, v.z, v.w);
}

void	print_mtx(t_mtx mtx)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < mtx.dim)
	{
		col = 0;
		while (col < mtx.dim)
		{
			printf("%.3f ", mtx.mtx[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}
