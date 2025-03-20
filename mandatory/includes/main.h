/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:48:29 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 20:59:41 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "tools.h"
# include "error.h"
# include "events.h"
# include "gc.h"
# include "guards.h"
# include "libs.h"
# include "shaders.h"

# define DOUBLE_MAX 1000000
# define DOUBLE_MIN -1000000

# ifndef EPSILON
#  define EPSILON 1e-6
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIN_WIDTH 1000

# define WIN_TITLE "MiniRT"

# define MAX_SCREEN_DIST 10
# define DFLT_SCREEN_DIST 1
# define MAX_COLOR_VALUE 0xFFFFFF
# define ROT_SPEED 0.4
# define MOVE_SPEED 0.4
# define DIV_SCALE 0.5
# define MUL_SCALE 2
# define X_AXIS 0
# define Y_AXIS 1
# define Z_AXIS 2

// map:
t_scene		*scene(void);

// writers
void		insert_light(t_light *light);
void		insert_ambient_light(t_tambient_light *a_light);
void		insert_cylinder(t_cylinder *cylinder);
void		insert_plane(t_plane *plane);
void		insert_sphere(t_sphere *sphere);
void		insert_cone(t_cone *cone);

void		read_map_data(char *filename);

// mlx:
void		**mlx(void);
void		**mlx_win(void);
t_data		*data(void);
void		put_pixel(int x, int y, int color);
void		flush(void);
int			events(void);

bool		is_in_fov(t_vec3 *center);
double		calc_focal(double vp_width);
void		calc_scene(t_render_range *rr);
void		render(void);

// intersections
double		instersect_sphere(t_ray *ray, t_sphere *sphere);
double		intersect_plane(t_ray *ray, t_plane *plane);
double		intersect_cylinder(t_ray *ray, t_cylinder *cylinder);
double		intersect_cone(t_ray *ray, t_cone *cone);

int			rgba(double r, double g, double b, double a);
t_color		from_hex(int hex);
int			to_hex(int r, int g, int b);
int			t_coloro_hex(t_color *color);

// rays
t_ray		*create_ray(t_vec3 origin, t_vec3 direction);
t_vec3		ray_point(t_ray *ray);
t_vec3		ray_at(t_ray *ray, double closest_t);

// intersections
double		instersect_sphere(t_ray *ray, t_sphere *sphere);
double		intersect_plane(t_ray *ray, t_plane *plane);
double		intersect_cylinder(t_ray *ray, t_cylinder *cylinder);
double		intersect_cone(t_ray *ray, t_cone *cone);

t_sphere	*get_closest_sphere(t_ray *ray, double *closest_t);
t_plane		*get_closest_plane(t_ray *ray, double *closest_t);
t_cylinder	*get_closest_cylinder(t_ray *ray, double *closest_t);
t_cone		*get_closest_cone(t_ray *ray, double *closest_t);

t_colord	t_coloro_double(t_color *color);
t_color		rgbd(double r, double g, double b);
#endif