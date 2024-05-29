# include "../include/minirt.h"
# include "../include/tests.h"

void free_inter(void *content)
{
	t_inter *inter_content = (t_inter *)content;
	// Set the shape pointer to NULL but don't free the shape
	inter_content->shape = NULL;
}

void test_inter(t_minirt *data)
{
	t_ray ray = get_ray((t_vec3){0, 0, -5, 1}, (t_vec3){0, 0, 1, 0});

	printf("\nA ray intersects a sphere at two points\n");
	intersections(data, ray);
	printf("expected count = 2: %d\n", ft_lstsize(data->xs));
	printf("expected inter1 = 4: %.3f\n", ((t_inter *)data->xs->content)->inter);
	printf("expected inter2 = 6: %.3f\n", ((t_inter *)data->xs->next->content)->inter);
	ft_lstclear(&data->xs, free_inter);

	printf("\nA ray intersects the sphere at two points\n");
	ray = get_ray((t_vec3){0, 1, -5, 1}, (t_vec3){0, 0, 1, 0});
	intersections(data, ray);
	printf("expected count = 1: %d\n", ft_lstsize(data->xs));
	printf("expected inter1 = 5: %.3f\n", ((t_inter *)data->xs->content)->inter);
	ft_lstclear(&data->xs, free_inter);

	printf("\nA ray misses the sphere\n");
	ray = get_ray((t_vec3){0, 2, -5, 1}, (t_vec3){0, 0, 1, 0});
	intersections(data, ray);
	printf("expected count = 0: %d\n", ft_lstsize(data->xs));
	ft_lstclear(&data->xs, free_inter);

	printf("\nA ray originates inside the sphere\n");
	ray = get_ray((t_vec3){0, 0, 0, 1}, (t_vec3){0, 0, 1, 0});
	intersections(data, ray);
	printf("expected count = 2: %d\n", ft_lstsize(data->xs));
	printf("expected inter1 = -1: %.3f\n", ((t_inter *)data->xs->content)->inter);
	printf("expected inter2 = 1: %.3f\n", ((t_inter *)data->xs->next->content)->inter);
	ft_lstclear(&data->xs, free_inter);

	printf("\nA sphere is behind a ray\n");
	ray = get_ray((t_vec3){0, 0, 5, 1}, (t_vec3){0, 0, 1, 0});
	intersections(data, ray);
	printf("expected count = 2: %d\n", ft_lstsize(data->xs));
	printf("expected inter1 = -6: %.3f\n", ((t_inter *)data->xs->content)->inter);
	printf("expected inter2 = -4: %.3f\n", ((t_inter *)data->xs->next->content)->inter);
	ft_lstclear(&data->xs, free_inter);
}
