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

t_pointlight	pointlight(t_vec3 position, t_color intensity)
{
	return ((t_pointlight){
		.position = position,
		.intensity = intensity,
	});
}

t_material default_material()
{
    t_material m = {
        .color = {1, 1, 1},
        .ambient = {0.1, 0.1, 0.1},
        .diffuse = 0.9,
        .specular = 0.9,
        .shininess = 200.0
    };
    return (m);
}

t_color	mult_colors(t_color a, t_color b)
{
	return ((t_color){
		a.r * b.r,
		a.g * b.g,
		a.b * b.b
	});
}
t_color	mult_color_scalar(t_color color, double scalar)
{
	return ((t_color){
		color.r * scalar,
		color.g * scalar,
		color.b * scalar,
	});
}

t_color color_add(t_color color1, t_color color2)
{
    return (t_color){
        color1.r + color2.r,
        color1.g + color2.g,
        color1.b + color2.b
    };
}

//heavy copilot reliance -> needs testing!
t_color lighting(t_material material, t_pointlight light, t_vec3 point, t_vec3 eyev, t_vec3 normalv)
{
    t_color effective_color = mult_colors(material.color, light.intensity);
    print_color(effective_color, "Effective color");
    t_vec3 lightv = vec_norm(vec_sub(light.position, point));
    t_color ambient = mult_colors(effective_color, material.ambient);
    print_color(ambient, "Ambient");
    double light_dot_normal = vec_dot(lightv, normalv);
    t_color diffuse;
    t_color specular;
    if (light_dot_normal < 0)
    {
        diffuse = (t_color){0, 0, 0};
        specular = (t_color){0, 0, 0};
    }
    else
    {
        diffuse = mult_color_scalar(effective_color, material.diffuse * light_dot_normal);
        t_vec3 reflectv = reflect(vec_neg(lightv), normalv);
        double reflect_dot_eye = vec_dot(reflectv, eyev);
        if (reflect_dot_eye <= 0)
            specular = (t_color){0, 0, 0};
        else
        {
            double factor = pow(reflect_dot_eye, material.shininess);
            specular = mult_color_scalar(light.intensity, material.specular * factor);
        }
        print_color(diffuse, "Diffuse");
        print_color(specular, "Specular");
    }
    return (color_add(color_add(ambient, diffuse), specular));
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

    t_color intensity = {1, 1, 1};
    t_vec3 position = {0, 0, 0, 1};
    t_pointlight light = pointlight(position, intensity);
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


void print_color(t_color color, char *description) {
    printf("%s: (%f, %f, %f)\n", description, color.r, color.g, color.b);
}

void print_material(t_material material) {
    printf("Material:\n");
    print_color(material.ambient, "Ambient");
    printf("Diffuse: %f\n", material.diffuse);
    printf("Specular: %f\n", material.specular);
    printf("Shininess: %f\n", material.shininess);
}
