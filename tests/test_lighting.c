/* move/delete tests as they won't work after refactoring
void test_light(t_minirt *data)
{
	t_sphere *s = malloc(sizeof(t_sphere));
	s->center = (t_vec3){0, 0, 0, 1};
	s->diameter = 1;
	s->color = (t_color){255, 0, 0};

	t_vec3 p = {1, 0, 0, 1};

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

	t_color intensity = {1, 1, 1};
	t_vec3 position = {0, 0, 0, 1};
	t_pntlight light = pointlight(position, intensity);
	print_vec3(light.position, "Light position");
	print_color(light.intensity, "Light intensity");

	t_material m = {
	.color = {1, 1, 1},
	.ambient = {0.1, 0.1, 0.1},
	.diffuse = 0.9,
	.specular = 0.9,
	.shininess = 200.0
	};
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

	m = (t_material){
		.color = {1, 1, 1},
		.ambient = {0.1, 0.1, 0.1},
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200.0
	};

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
	print_color(result, "Result color");
}
*/
