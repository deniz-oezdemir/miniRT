# include "../include/minirt.h"

static t_mtx	orientation_mtx(t_minirt *data, t_vec3 left, t_vec3 true_up, t_vec3 forward)
{
	double	m[] = {
	left.x, left.y, left.z, 0,
	true_up.x, true_up.y, true_up.z, 0,
	-forward.x, -forward.y, -forward.z, 0,
	0, 0, 0, 1};
	return (create_mtx(data, (const double *)m, 4));
}

/* Transform the world objet according to the point of view		*/
/* Parameters:													*/
/* from: the point where you want the eye to be in the scene	*/
/* to: the point in the scene at which you want to look			*/
/* up:  vector defining which direction is up in the world		*/
t_mtx	transform_view(t_minirt *data, t_vec3 from, t_vec3 to, t_vec3 up)
{
	t_vec3	forward;
	t_vec3	left;
	t_vec3	true_up;
	t_mtx	orientation;

	forward = vec_norm(vec_sub(to, from));
	left = vec_cross(forward, vec_norm(up));
	true_up = vec_cross(left, forward);
	orientation = orientation_mtx(data, left, true_up, forward);
	return (mult_mtx_mtx(data, orientation,
		translation_mtx(data, -from.x, -from.y, -from.z)));
}
