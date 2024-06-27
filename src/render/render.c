/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:34:55 by denizozd          #+#    #+#             */
/*   Updated: 2024/06/27 17:30:31 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_comps	prepare_computations(t_inter inter, t_ray ray)
{
	t_comps	comps;

	comps.t = inter.inter;
	comps.shape = inter.shape;
	comps.point = position(ray, inter.inter);
	comps.eyev = vec_neg(ray.dir);
	comps.normalv = normal_at(inter.shape, comps.point);
	comps.inside = false;
	if (vec_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = vec_neg(comps.normalv);
	}
	comps.over_point = vec_add(comps.point, vec_mul(EPSILON, comps.normalv));
	return (comps);
}

int	is_shadow(t_minirt *data, t_vec3 light_position, t_vec3 over_point)
{
	t_vec3	v;
	t_ray	ray;

	v = vec_sub(light_position, over_point);
	ray = (t_ray){over_point, vec_norm(v)};
	intersections(data, ray);
	if (data->min.inter < (magnitude(v) - EPSILON)
		&& data->min.inter > -EPSILON)
		return (1);
	return (0);
}

t_color	shade_hit(t_minirt *data, t_world *world, t_comps comps)
{
	t_color		color;
	t_color		ambient;
	t_list		*lights;
	t_pntlight	*light;

	lights = world->lights;
	ambient = mult_colors(comps.shape->color, world->ambient_light->light);
	if (lights == NULL)
		return (ambient);
	color = (t_color){0, 0, 0};
	while (lights != NULL)
	{
		light = &((t_light *)lights->content)->pnt_light;
		light->shadow = is_shadow(data, light->center, comps.over_point);
		color = color_add(color, lighting(comps, ambient, light));
		lights = lights->next;
	}
	return (color);
}

/* initialize color to background color */
t_color	color_at(t_minirt *data, t_ray ray)
{
	t_inter	hit_inter;
	t_comps	comps;
	t_color	color;

	color = (t_color){0.125, 0.125, 0.125};
	intersections(data, ray);
	hit_inter = data->min;
	if (hit_inter.shape != NULL)
	{
		comps = prepare_computations(hit_inter, ray);
		color = shade_hit(data, data->world, comps);
	}
	return (color);
}

void	render_scene(t_minirt *data)
{
	double	x;
	double	y;
	t_ray	ray;
	t_color	color;

	print_instruction(data);
	y = -1.0;
	ft_printf("Start rendering...\n");
	while (++y < data->world->camera->vsize)
	{
		ft_printf("\rRendering: %d%%", (int)(y * 100.0 / IMG_HEIGHT));
		x = -1.0;
		while (++x < data->world->camera->hsize)
		{
			ray = cast_ray(data->world->camera, x, y);
			color = color_at(data, ray);
			color_pixel(data, x, y, rgb(color));
		}
	}
	ft_printf("\rRendering: 100%%\n");
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img->img_ptr, 200, 0);
}
