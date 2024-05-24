# include "../include/tests.h"

void test_rays()
{
	t_vec3 o = {1.0, 2.0, 3.0, 1.0};
	t_vec3 d = {4, 5, 6, 0};
	double m = 3.0;

	printf("\n--- Test Rays ---\n");
	printf("Source Vectors:\n");
	print_vec3(o, "origin");
	print_vec3(d, "direction");

	printf("\nGet ray:\n");
	t_ray r = get_ray(o, d);
	print_vec3(r.origin, "ray.origin =");
	print_vec3(r.dir, "ray.direction =");

	printf("\nCompute a point from a distance:\n");
	t_vec3 p = {2, 3, 4, 1};
	t_vec3 v = {1, 0 , 0 , 0};
	r = get_ray(p, v);
	print_vec3(position(r, 0.0), "expected point 2, 3, 4");
	print_vec3(position(r, 1.0), "expected point 3, 3, 4");
	print_vec3(position(r, -1.0), "expected point 1, 3, 4");
	print_vec3(position(r, 2.5), "expected point 4.5, 3, 4");
}
