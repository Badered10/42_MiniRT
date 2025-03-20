/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:35:23 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/19 03:38:18 by baouragh         ###   ########.fr       */
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

# define EPSILON 1e-6

# define M_PI 3.14159265358979323846

# define WIN_WIDTH 1000

# define WIN_TITLE "MiniRT"

// map:
t_sys_data	*sys_data(void);
t_scene		*scene(void);

// writers
void		insert_light(t_light *light);
void		insert_ambient_light(t_ambient_light *a_light);
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

bool		is_in_fov(t_vec3 *center);

double		calc_focal(double vp_width);
void		calc_scene(t_render_range *rr);
void		*render(void *rr);
void		render_scene(void);

// intersections
double		instersect_sphere(t_ray *ray, t_sphere *sphere);
double		intersect_plane(t_ray *ray, t_plane *plane);
double		intersect_cylinder(t_ray *ray, t_cylinder *cylinder);
double		intersect_cone(t_ray *ray, t_cone *cone);

t_color		from_hex(int hex);
int			to_hex(int r, int g, int b);
int			t_coloro_hex(t_color *color);

// rays
t_ray		*create_ray(t_vec3 origin, t_vec3 direction);
t_vec3		ray_point(t_ray *ray);
t_vec3		ray_at(t_ray *ray, double closest_t);

// patterns
void		compute_pattern(t_ray *ray, double closest_t, t_plane *plane);

t_sphere	*get_closest_sphere(t_ray *ray, double *closest_t);
t_plane		*get_closest_plane(t_ray *ray, double *closest_t);
t_cylinder	*get_closest_cylinder(t_ray *ray, double *closest_t);
t_cone		*get_closest_cone(t_ray *ray, double *closest_t);

void		destroy_textures(void);

t_colord	t_coloro_double(t_color *color);
t_color		rgbd(double r, double g, double b);

#endif
