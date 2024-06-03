#include "../../include/minirt.h"

// malloc if different materials needed for different objects
// change values to modify phong model
t_material default_material()
{
	t_material m = {
		.diffuse = 0.9,
		.specular = 0.9, // added from book, not provided by subject
		.shininess = 200.0};
	return (m);
}
