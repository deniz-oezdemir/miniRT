# include "../include/minirt.h"
# include "../include/tests.h"


void test_inter()
{
	t_ray ray = get_ray((t_vec3){0, 0, -5, 1}, (t_vec3){0, 0, 1, 0});
	t_sphere s;

	s.name = "sp";
	s.x = 0;
	s.y = 0;
	s.z = 0;
	s.diameter = 0.5;
	s.r = 0;
	s.g = 0;
	s.b = 0;

	printf("\nA ray intersects a sphere at two points\n");
	t_inter i = inter_sphere(&s, ray);
	printf("expected count = 2: %d\n", i.count);
	printf("expected inter1 = 4: %.3f\n", i.i1);
	printf("expected inter2 = 6: %.3f\n", i.i2);

	printf("\nA ray intersects a sphere at two points\n");
	ray = get_ray((t_vec3){0, 1, -5, 1}, (t_vec3){0, 0, 1, 0});
	i = inter_sphere(&s, ray);
	printf("expected count = 1: %d\n", i.count);
	printf("expected inter1 = 5: %.3f\n", i.i1);
	printf("expected inter2 = 5: %.3f\n", i.i2);

	printf("\nA ray misses a sphere\n");
	ray = get_ray((t_vec3){0, 2, -5, 1}, (t_vec3){0, 0, 1, 0});
	i = inter_sphere(&s, ray);
	printf("expected count = 0: %d\n", i.count);
	printf("inter1 set to 0: %.3f\n", i.i1);
	printf("inter2 set to 0: %.3f\n", i.i2);

	printf("\nA ray originates inside a sphere\n");
	ray = get_ray((t_vec3){0, 0, 0, 1}, (t_vec3){0, 0, 1, 0});
	i = inter_sphere(&s, ray);
	printf("expected count = 2: %d\n", i.count);
	printf("expected inter1 = -1: %.3f\n", i.i1);
	printf("expected inter2 = 1: %.3f\n", i.i2);

	printf("\nA sphere is behind a ray\n");
	ray = get_ray((t_vec3){0, 0, 5, 1}, (t_vec3){0, 0, 1, 0});
	i = inter_sphere(&s, ray);
	printf("expected count = 2: %d\n", i.count);
	printf("expected inter1 = -6: %.3f\n", i.i1);
	printf("expected inter2 = -4: %.3f\n", i.i2);
}
