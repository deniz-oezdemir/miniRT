//  move - delete tests as they won't work after refactoring
# include "../include/minirt.h"
# include "../include/tests.h"

void test_light(t_minirt *data)
{
	t_vec3 p = point(99,99,99);
	printf ("\n*** Test normal ch.6 (with camera) ***\n\n");
	free_world(data->world);
	parse(data, "scene_2_sphere_first_render.rt");

	t_ray ray = cast_ray(data->world->camera, 150, 150);
	intersections(data, ray);
	t_inter hit_inter = hit(data->xs);
	printf("hit: %f\n", hit_inter.inter);
	if (hit_inter.shape != NULL)
	{
		printf("hit: %f\n", hit_inter.inter);
		t_vec3 p = position(ray, hit_inter.inter);
		print_vec3(p, "Position");
	}

	// t_vec3 p = {1, 0, 0, 1};
	t_sphere *s = &((t_shape *)data->world->objects->content)->sphere;

	print_vec3(normal_at(s, p), "The normal on a sphere at a point on the x axis");

	p = (t_vec3){0, 1, 0, 1};
	print_vec3(normal_at(s, p), "The normal on a sphere at a point on the y axis");

	p = (t_vec3){0, 0, 1, 1};
	print_vec3(normal_at(s, p), "The normal on a sphere at a point on the z axis");

	float sqrt3_over_3 = sqrt(3) / 3;
	p = (t_vec3){sqrt3_over_3, sqrt3_over_3, sqrt3_over_3, 1};
	print_vec3(normal_at(s, p), "The normal on a sphere at a nonaxial point");

	t_vec3 n = normal_at(s, p);
	print_vec3(n, "The normal before normalization");
	n = vec_norm(n);
	print_vec3(n, "The normal after normalization");

	//pp.79: transforming normals not needed for us?

	t_vec3 v = {1, -1, 0, 0};
	n = (t_vec3){0, 1, 0, 0};
	t_vec3 r = reflect(v, n);
	print_vec3(r, "Reflecting a vector approaching at 45°");

	v = (t_vec3){0, -1, 0, 0};
	n = (t_vec3){sqrt(2) / 2, sqrt(2) / 2, 0, 0};
	r = reflect(v, n);
	print_vec3(r, "Reflecting a vector off a slanted surface");

	/* t_color intensity = {1, 1, 1};
	t_vec3 position = {0, 0, 0, 1};
	t_pntlight light = pointlight(position, intensity);
	print_vec3(light.position, "Light position");
	print_color(light.intensity, "Light intensity");


	print_color(m.color, "Material color");
	print_color(m.ambient, "Material ambient");
	printf("Material diffuse: %f\n", m.diffuse);
	printf("Material specular: %f\n", m.specular);
	printf("Material shininess: %f\n", m.shininess);

	t_vec3 eyev = {0, 0, -1, 0};
	t_vec3 normalv = {0, 0, -1, 0};
	position = (t_vec3){0, 0, 0, 1};
	intensity = (t_color){1, 1, 1};
	light = pointlight((t_vec3){0, 0, -10, 1}, intensity);


	t_color result = lighting(m, light, position, eyev, normalv);

	printf("\nTest: Lighting with the eye between the light and the surface\n");
	print_color(result, "Result color");


	eyev = (t_vec3){0, sqrt(2)/2, -sqrt(2)/2, 0};
	normalv = (t_vec3){0, 0, -1, 0};
	result = lighting(m, light, position, eyev, normalv);
	printf("\nTest: Lighting with the eye between the light and the surface, eye offset 45 degrees\n");
	print_color(result, "Result color");

	eyev = (t_vec3){0, 0, -1, 0};
	normalv = (t_vec3){0, 0, -1, 0};
	light = pointlight((t_vec3){0, 10, -10, 1}, intensity);
	result = lighting(m, light, position, eyev, normalv);
	printf("\nTest: Lighting with eye opposite surface, light offset 45 degrees\n");
	print_color(result, "Result color");

	eyev = (t_vec3){0, -sqrt(2)/2, -sqrt(2)/2, 0};
	normalv = (t_vec3){0, 0, -1, 0};
	light = pointlight((t_vec3){0, 10, -10, 1}, intensity);
	result = lighting(m, light, position, eyev, normalv);
	printf("\nTest: Lighting with eye in the path of the reflection vector\n");
	print_color(result, "Result color");

	eyev = (t_vec3){0, 0, -1, 0};
	normalv = (t_vec3){0, 0, -1, 0};
	light = pointlight((t_vec3){0, 0, 10, 1}, intensity);
	result = lighting(m, light, position, eyev, normalv);
	printf("\nTest: Lighting with the light behind the surface\n");
	print_color(result, "Result color"); */
}

