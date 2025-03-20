/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:04:57 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/17 23:55:45 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "tools.h"

int			events(void);

// hook tools
void		xd_hundler(void *shape, double angle, int type);
void		yd_hundler(void *shape, double angle, int type);
void		zd_hundler(void *shape, double angle, int type);

void		translate_shape(t_object *obj, t_vec3 translation_vector);
void		scale_diameter(t_object *obj, double scale_factor, bool mod);
void		move_any(int keycode, bool *render);
t_ray		do_ray(double x, double y);

void		camera_hundler(int keycode, bool *render);
t_object	*closest_obj(t_ray *ray);
void		rotate_shape(void *shape, double angle, int type, int axis);

int			safe_close(int ntn);
void		move_maper(int keycode, bool *render);

#endif