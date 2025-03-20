/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:47:39 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 06:03:16 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

enum						e_keys
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	CTRL = 65507,
	K = 107,
	I = 105,
	L = 106,
	J = 108,
	U = 117,
	O = 111,
	PLUS = 61,
	MIN = 45,
	LEFT_X = 65361,
	FORWORD_Z = 65362,
	RIGHT_X = 65363,
	BACK_Z = 65364,
	UP_Y = 65365,
	DWON_Y = 65366,
	ALT = 65513,
	BACKSPACE = 65288,
};

typedef struct s_data
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}							t_data;

typedef struct t_vec2_s
{
	double					x;
	double					y;
}							t_vec2;

typedef struct t_s_vec3
{
	double					x;
	double					y;
	double					z;
}							t_vec3;

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
	t_colord	a;
	t_colord	b;
	t_colord	c;
	t_vec3		*point; //remove
}	t_trp_clrd;

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
}							t_tambient_light;

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
# define LIGHT 4

typedef struct object_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	void					*shape;
}							t_object;

typedef struct sphere_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
	double					diameter;
	struct sphere_s			*next;
}							t_sphere;

typedef struct plane_s
{
	int8_t					type;
	t_vec3					pos;
	t_color					color;
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

typedef struct scene_s
{
	t_camera				*camera;
	t_tambient_light		*ambient_light_list;
	t_light					*light_list;
	t_sphere				*sphere_list;
	t_plane					*plane_list;
	t_cylinder				*cylinder_list;
	t_cone					*cone_list;
	t_object				*obj_to_move;
	int						screen_height;
	int						screen_width;
	int						aa_round;
}							t_scene;

typedef struct ray_s
{
	t_vec3					origin;
	t_vec3					direction;
	double					t;
	double					t_max;
	t_color					color;
}							t_ray;

typedef struct render_range_s
{
	t_vec3					camera_center;
	t_vec3					h_pixel_delta;
	t_vec3					v_pixel_delta;
	t_vec3					viewport_upper_left;

	int						color;

}							t_render_range;

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
t_vec3						rotate_z(t_vec3 v, double angle);
t_vec3						rotate_x(t_vec3 v, double angle);
t_vec3						rotate_y(t_vec3 v, double angle);

#endif