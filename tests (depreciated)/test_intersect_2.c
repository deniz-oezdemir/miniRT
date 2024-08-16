# include "../include/minirt.h"
# include "../include/tests.h"

/* void test_inter_2(t_minirt *data)
{
	printf ("\n*** Test intersections 2 spheres ***\n\n");
	free_world(data->world);
	parse(data, "scene_2_sphere.rt");

	t_ray ray = cast_ray((t_vec3){0, 0, 0, 1}, (t_vec3){0, 1, 0, 0});

	printf("\nA ray intersects 2 spheres at 4 points\n");
	intersections(data, ray);
	printf("expected count = 4: %d\n", ft_lstsize(data->xs));
	printf("expected inter1 = 1: %.3f\n", ((t_inter *)data->xs->content)->inter);
	printf("expected inter2 = 3: %.3f\n", ((t_inter *)data->xs->next->content)->inter);
	printf("expected inter3 = 3: %.3f\n", ((t_inter *)data->xs->next->next->content)->inter);
	printf("expected inter4 = 5: %.3f\n", ((t_inter *)data->xs->next->next->next->content)->inter);

	printf("\nClosest hit intersection: %.3f\n", hit(data->xs).inter);
	ft_lstclear(&data->xs, free_inter);

	ray = get_ray((t_vec3){0, 2.5, 0, 1}, (t_vec3){0, 1, 0, 0});

	printf("\nA ray intersects 2 spheres at 4 points - Ray origin in the first sphere\n");
	intersections(data, ray);
	printf("expected count = 4: %d\n", ft_lstsize(data->xs));
	printf("expected inter1 = -1.5: %.3f\n", ((t_inter *)data->xs->content)->inter);
	printf("expected inter2 = 0.5: %.3f\n", ((t_inter *)data->xs->next->content)->inter);
	printf("expected inter3 = 0.5: %.3f\n", ((t_inter *)data->xs->next->next->content)->inter);
	printf("expected inter4 = 2.5: %.3f\n", ((t_inter *)data->xs->next->next->next->content)->inter);

	printf("\nClosest hit intersection: %.3f\n", hit(data->xs).inter);
	ft_lstclear(&data->xs, free_inter);

} */
