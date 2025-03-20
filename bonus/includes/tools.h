/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:31:48 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/19 09:17:48 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "libs.h"

typedef struct data_s
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}							t_data;

typedef struct s_vec2
{
	double					x;
	double					y;
}							t_vec2;

typedef struct vec3_s
{
	double					x;
	double					y;
	double					z;
}							t_vec3;

typedef struct dim_s
{
	int						w;
	int						h;
}							t_dim;

typedef struct color_s
{
	u_int8_t				r;
	u_int8_t				g;
	u_int8_t				b;
}							t_color;

typedef struct colord_s
{
	double					r;
	double					g;
	double					b;
}							t_colord;

typedef struct trp_clrd_s
{
	t_colord				a;
	t_colord				b;
	t_colord				c;
	t_vec3					*point;
}							t_trp_clrd;

typedef struct camera_s
{
	t_vec3					pos;
	t_vec3					direction;
	int						fov;
	double					screen_dist;
}							t_camera;

typedef struct ambient_light_s
{
	double					lighting_ratio;
	t_color					color;
	struct ambient_light_s	*next;
}							t_ambient_light;

typedef struct light_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	double					brightness;
	struct light_s			*next;
	struct light_s			*prev;
}							t_light;

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3
# define CAMERA 4
# define LIGHT 5

typedef struct s_image
{
	char					*file_name;
	t_dim					size;
	t_data					data;
}							t_image;

typedef struct sphere_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	double					diameter;
	t_image					*texture;
	struct sphere_s			*next;
}							t_sphere;

// for spheres texture
typedef struct texture_req_s
{
	t_sphere				*sphere;
	struct texture_req_s	*next;
}							t_texture_req;

typedef struct plane_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	bool					ck;
	t_color					ck_colors[2];
	t_vec3					normal;
	struct plane_s			*next;
}							t_plane;

typedef struct cylinder_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	t_vec3					normal;
	double					diameter;
	double					height;
	struct cylinder_s		*next;
}							t_cylinder;

typedef struct cone_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	t_vec3					normal;
	double					diameter;
	double					height;
	struct cone_s			*next;
}							t_cone;

typedef struct render_range_s
{
	int						x_range[2];
	int						y_range[2];
	t_vec3					camera_center;
	t_vec3					h_pixel_delta;
	t_vec3					v_pixel_delta;
	t_vec3					viewport_upper_left;
}							t_render_range;

typedef struct sys_data_s
{
	int						screen_height;
	int						screen_width;
	int						cpu_cores;
	bool					full_render;
	pthread_mutex_t			pixel_lock;
	pthread_mutex_t			gc_lock;
	pthread_mutex_t			close_lock;
	int						aa_round;
	bool					noisy_effect;
}							t_sys_data;

typedef struct ray_s
{
	t_vec3					origin;
	t_vec3					direction;
	double					t;
	double					t_max;
	t_color					color;
}							t_ray;

typedef struct object_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	void					*shape;
}							t_object;

typedef struct scene_s
{
	t_camera				*camera;
	t_ambient_light			*ambient_light_list;
	t_light					*light_list;
	t_sphere				*sphere_list;
	t_texture_req			*texture_req_list;
	t_plane					*plane_list;
	t_cylinder				*cylinder_list;
	t_cone					*cone_list;
	t_object				*obj_to_move;
	t_light					*light_target;
	bool					light_selected;
}							t_scene;

typedef struct thread_s
{
	pthread_t				pid;
	t_render_range			range;
}							t_thread;

typedef struct s_compute_cyle
{
}							t_compute_cyle;

void						add_(t_vec3 *a, double b);
t_vec3						sub_(t_vec3 a, t_vec3 b);
t_vec3						sum_(t_vec3 a, t_vec3 b);
t_vec3						mult_(t_vec3 a, double b);
t_vec3						div_(t_vec3 a, double b);
void						norm_(t_vec3 *v);
t_vec3						cross_(t_vec3 a, t_vec3 b);
double						dot_(t_vec3 a, t_vec3 b);
void						sphere_cylinder_hit(void **closest_obj,
								double *closest_t, t_ray *ray);
void						cone_plane_hit(void **closest_obj,
								double *closest_t, t_ray *ray);
t_color						trace_a_ray(t_ray *ray);
t_color						compute_pixel_color(t_vec3 pixel_center,
								t_render_range *rr_);
void						xd_hundler(void *shape, double angle, int type);
void						yd_hundler(void *shape, double angle, int type);
void						zd_hundler(void *shape, double angle, int type);

#endif
