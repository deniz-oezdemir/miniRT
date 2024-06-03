#include "../include/minirt.h"

t_color lighting(t_minirt *data, t_shape *shape, t_pntlight *plight, t_vec3 point, t_vec3 eyev, t_vec3 normalv)
{
    t_color effective_color = mult_colors(shape->sphere.color, plight->light);
    t_vec3 lightv = vec_norm(vec_sub(plight->center, point));
    t_color ambient = mult_colors(effective_color, data->world->ambient_light->light);
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
        diffuse = mult_color_scalar(effective_color, shape->material.diffuse * light_dot_normal);
        t_vec3 reflectv = reflect(vec_neg(lightv), normalv);
        double reflect_dot_eye = vec_dot(reflectv, eyev);
        if (reflect_dot_eye <= 0)
            specular = (t_color){0, 0, 0};
        else
        {
            double factor = pow(reflect_dot_eye, shape->material.shininess);
            specular = mult_color_scalar(plight->light, shape->material.specular * factor);
        }
    }
    return (color_add(color_add(ambient, diffuse), specular));
}
