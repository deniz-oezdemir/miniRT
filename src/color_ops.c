# include "../include/minirt.h"

t_color color_add(t_color a, t_color b)
{
    return (t_color){
        a.r + b.r,
        a.g + b.g,
        a.b + b.b
    };
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

