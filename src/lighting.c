# include "../include/minirt.h"

t_vec3 normal_at(t_sphere *sphere, t_vec3 p)
{
	t_vec3 sphere_norm;

	sphere_norm = vec_sub(p, sphere->center);
	sphere_norm.w = 0.0;
	return (vec_norm(sphere_norm));
}

t_vec3 reflect(t_vec3 in, t_vec3 normal)
{
	return (vec_sub(in, vec_mul(vec_dot(in, normal), vec_mul(2.0, normal))));
}

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
}

//t_color lighting(...)
