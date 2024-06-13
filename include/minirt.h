#ifndef MINIRT_H
# define MINIRT_H

# include "objects.h"
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include <X11/keysym.h>
# include "../lib/libft/libft.h"
# include "errors.h"
# include "math.h"
# include "tuples.h"

# define WIN_NAME	"MiniRT"
# define WIN_WIDTH	1000
# define WIN_HEIGHT	800

# define IMG_WIDTH	500
# define IMG_HEIGHT	500

# define BACKGROUND_COLOR	0x202020
# define TEXT_COLOR			0xffffff

# define MLX_ERROR	1

# define MTX_DIM	4 //matrix dimension, maybe just substitute MTX_DIM with 4 everywhere at the end
# define MTX_SIZE	16 //matrix number of elements, must be set to MTX_DIM^2
# define PI 3.14159265358979323846
# define PI_2 1.57079632679489661923
# define EPSILON		0.00001

typedef struct s_material t_material;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_world
{
	t_list		*objects;
	t_list		*lights;
	t_amblight	*ambient_light;
	t_camera	*camera;
	int		object_nbr;
	int		light_nbr;
}	t_world;

typedef struct s_minirt
{
	int			fd;
	t_list		*scene;
	t_list		*objects;
	t_list		*grbg;
	t_world		*world;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*mlx_img;
	t_list		*xs;
	// t_scene	*scene;
}	t_minirt;

typedef struct s_inter
{
	t_shape	*shape;
	double	inter;
}	t_inter;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

/* discriminiant type to perform calculations only once */
typedef struct s_discr
{
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	double	discr;
}	t_discr;

typedef struct s_comps
{
	double	t;
	t_shape	*shape;
	t_vec3	point;
	t_vec3	eyev;
	t_vec3	normalv;
	bool	inside;
	// t_vec3	over_point;
}	t_comps;

typedef struct s_exposure
{
	t_color	effective_color;
	t_vec3	lightv;
	t_vec3	reflectv;
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;
}	t_exposure;


/* Init and exit functions */
t_minirt	*init_mlx(void);
t_mtx	create_mtx(const double *m, size_t dim);
void	init_window(t_minirt *data);
void	init_camera_view(t_camera *camera);
void	exit_program(t_minirt *data);

/* MLX keyboard and mouse hooks */
int		handle_keyboard_input(int keysym, t_minirt *data);
int		handle_mouse_input(int keysym, t_minirt *data);
int		handle_close_button(t_minirt *data);

/* Window functions */
void	color_pixel(t_minirt *data, int x, int y, int color);
void	color_background(t_minirt *data, int color);
void	print_instruction(t_minirt *data);

/* Parsing */
void	parse(t_minirt *data, char *file_name);
void	parse_ambient_light(t_minirt *data, t_list **al);
void	parse_camera(t_minirt *data, t_list **list);
void	parse_pnt_light(t_minirt *data, t_list **list);
void	parse_sphere(t_minirt *data, t_list **list);
void	parse_plane(t_minirt *data, t_list **list);
void	parse_cylinder(t_minirt *data, t_list **list);

/* Input validation */
bool	is_digits(char *s);
bool	is_identifier(char *s);
bool	is_in_range(double min, double max, char *s);

double	check_intensity(char *arg);
int		check_rgb(char *arg);
double	check_coordinate(char *arg);
int		check_vec3(char *arg);
int		check_fov(char *arg);

/* Handlers */
void	pars_error(t_minirt *data, int err_code);

/* Utils */
double	atof(const char *str);
void	swap(double *nbr1, double *nbr2);
void	remove_newline(char **str);
void	*get_nth_content(t_list *list, int n);
void	move_to_nth_node(t_list **list, int n);
double	deg_to_rad(double degrees);
void	free_inter(void *content);
int		rgb(t_color color);
void	set_transform(t_shape *shape, t_mtx transform);
t_vec3	point(double x, double y, double z);
t_vec3	vector(double x, double y, double z);
void	calculate_rotation_angles(t_vec3 vec, double *x, double *y, double *z);

/* Garbage collector */
void	*gc_get(t_minirt *data, size_t nmemb, size_t size);
void	gc_collect(t_minirt *data, void *new);
void	gc_free(t_list *grbg);

t_list	*gc_lstnew(t_minirt *data, void *content);
char	**gc_split(t_minirt *data, char const *s, char c);
char	*gc_substr(t_minirt *data, char const *s, unsigned int start,
		size_t len);

/* Matrix operations*/
t_mtx	mult_mtx_mtx(t_mtx a, t_mtx b);
t_mtx	transp_mtx(t_mtx m);
t_mtx	invert_mtx(t_mtx m);

/* Matrix transformations */
t_mtx	scaling(double x, double y, double z);
t_mtx	rot_x(double radians);
t_mtx	rot_y(double radians);
t_mtx	rot_z(double radians);
t_mtx	translation_mtx(double x, double y, double z);
t_mtx	rotation_mtx(t_vec3 vector);

double	determinant_2x2(t_mtx m);
t_mtx	sub_mtx(t_mtx m, int x_row, int x_col);
double	mtx_minor(t_mtx m, int x_row, int x_col);
double	mtx_cofactor(t_mtx m, int row, int col);
double	mtx_determinant(t_mtx m);
t_mtx	identity_mtx(size_t dim);

/* Matrix transformations */
t_mtx	translation_mtx(double x, double y, double z);

t_mtx	rot_x(double radians);
t_mtx	rot_y(double radians);
t_mtx	rot_z(double radians);
t_mtx	rotation_mtx(t_vec3 vec);

/* Vector operations */
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
t_vec3	vec_mul(double a, t_vec3 b);
t_vec3	vec_div(double a, t_vec3 b);
t_vec3	vec_neg(t_vec3 v);
t_vec3	vec_norm(t_vec3 a);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
t_vec3	mult_pnt_mtx(t_vec3 p, t_mtx m);
t_vec3	normal_at(t_shape *shape, t_vec3 p);
t_vec3	reflect(t_vec3 in, t_vec3 normal);

double	vec_dot(t_vec3 a, t_vec3 b);
double	magnitude(t_vec3 v);

/* Ray casting */
// input = ray, distance (double) || output Position = Point(vec3)
t_ray	cast_ray(t_camera *camera, int px, int py);
t_ray	transform_ray(t_ray ray, t_shape *shape);
t_vec3	position(t_ray ray, double dist);

/* Ray intersects sphere */
void	intersections(t_minirt *minirt, t_ray ray);
bool	inter_sphere(t_minirt *data, t_shape *shape, t_ray ray);
t_discr	discriminant(t_sphere *sphere, t_ray ray);
t_inter	hit(t_list *xs);

/* Render scene */
void	render_scene(t_minirt *data);

/* Lighting */
t_material		default_material(void);
t_color			lighting(t_comps comps, t_color ambient, t_pntlight *plight);

/* Color operations */
t_color	color_add(t_color a, t_color b);
t_color	mult_colors(t_color a, t_color b);
t_color	mult_color_scalar(t_color color, double scalar);

/* Camera */
t_mtx	transform_view(t_vec3 from,t_vec3 to,t_vec3 up);

/* Print stuffs */
// To be deleted befor submission
void	print_scene_objects(t_world *world);
void	print_vec3(t_vec3 v, char* label);
void	print_mtx(t_mtx mtx);
void	print_material(t_material material);
void	print_color(t_color color, char *description);
void print_light(t_pntlight *obj);

#endif
