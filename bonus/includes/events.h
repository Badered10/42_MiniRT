/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:33:47 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 06:08:05 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

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

enum		e_keys
{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	CTRL = 65507,
	K = 107,
	I = 105,
	L = 108,
	J = 106,
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
	SPACE = 32
};

int			safe_close(int ntn);

int			events(void);

t_vec3		rotate_z(t_vec3 v, double angle);
t_vec3		rotate_x(t_vec3 v, double angle);
t_vec3		rotate_y(t_vec3 v, double angle);

void		translate_shape(t_object *obj, t_vec3 translation_vector);
void		scale_diameter(t_object *obj, double scale_factor, bool mod);
void		move_any(int keycode, bool *render);
t_ray		do_ray(double x, double y);

void		camera_hundler(int keycode, bool *render);
t_object	*closest_obj(t_ray *ray);
void		rotate_shape(void *shape, double angle, int type, int axis);

void		move_maper(int keycode, bool *render);
t_object	*objects_selecter(int btn, int x, int y);
int			event_mapper(int keycode);

#endif
