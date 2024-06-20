#include "../../include/minirt.h"

// malloc if different materials needed for different objects
t_material	default_material(void)
{
	return ((t_material){
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 200.0});
}
