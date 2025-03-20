/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:00:10 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:58:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	calc_focal(double vp_width)
{
	double	fov_rad;
	double	focal_length;

	fov_rad = scene()->camera->fov * M_PI / 180.0;
	focal_length = (vp_width / 2.0) / tan(fov_rad / 2.0);
	return (fmax(focal_length, .5));
}

void	prepare_forword_vec(t_render_range *rr, t_vec3 *forward)
{
	t_vec3	t_cameraarget;

	rr->camera_center = scene()->camera->pos;
	t_cameraarget = scene()->camera->direction;
	*forward = sub_(t_cameraarget, rr->camera_center);
	norm_(&(*forward));
}

void	prepare_up_right_vec(t_vec3 *up, t_vec3 *right,
		t_vec3 forward)
{
	*up = (t_vec3){0, 1, 0};
	*right = cross_(forward, *up);
	norm_(&(*right));
	*up = cross_(forward, *right);
}

void	prepare_camera(t_render_range *rr, t_vec3 up, t_vec3 right,
		t_vec3 forward)
{
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	viewport_center;
	double	viewport_height;
	double	viewport_width;

	viewport_height = 2.0;
	viewport_width = viewport_height * ((double)scene()->screen_width
			/ (double)scene()->screen_height);
	horizontal = mult_(right, viewport_width);
	vertical = mult_(up, viewport_height);
	rr->h_pixel_delta = div_(horizontal, scene()->screen_width);
	rr->v_pixel_delta = div_(vertical, scene()->screen_height);
	viewport_center = sum_(rr->camera_center, mult_(forward,
				calc_focal(viewport_width)));
	rr->viewport_upper_left = sub_(sub_(viewport_center, div_(horizontal, 2)),
			div_(vertical, 2));
}

void	calc_scene(t_render_range *rr)
{
	t_vec3	forward;
	t_vec3	up;
	t_vec3	right;

	prepare_forword_vec(rr, &forward);
	prepare_up_right_vec(&up, &right, forward);
	prepare_camera(rr, up, right, forward);
}
