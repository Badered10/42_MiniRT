/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:51:48 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 23:19:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	ambient_light(void)
{
	if (scene()->ambient_light_list)
		return (scene()->ambient_light_list->lighting_ratio);
	return (.3);
}

double	diffuse_light(t_vec3 *normal, t_vec3 *light_vec,
		double brightness, double distance)
{
	return ((fmax(dot_(*normal, *light_vec), 0.0) * brightness) / (distance));
}

double	specular_light(t_vec3 *point, t_vec3 *normal, t_light *l)
{
	double	spec_angle;
	t_vec3	light_dir;
	t_vec3	reflect_dir;
	t_vec3	view_dir;
	double	distance;

	light_dir = sub_(l->pos, *point);
	distance = sqrt(dot_(light_dir, light_dir));
	if (distance == 0)
		return (0);
	norm_(&light_dir);
	reflect_dir = sub_(mult_(*normal, 2 * dot_(*normal, light_dir)), light_dir);
	norm_(&reflect_dir);
	view_dir = sub_(scene()->camera->pos, *point);
	norm_(&view_dir);
	spec_angle = fmax(dot_(reflect_dir, view_dir), 0.0);
	return (fmax((sin(spec_angle) * l->brightness / distance), 0.0));
}

void	effect_shadow(t_shadow *shad)
{
	t_vec3	inters_point;
	double	distance;

	shad->shadow_ray.t = shad->t;
	inters_point = ray_point(&shad->shadow_ray);
	distance = sqrt(dot_(sub_(inters_point, shad->shadow_origin),
				sub_(inters_point, shad->shadow_origin)));
	if (distance < shad->distance_to_light && distance > shad->delta)
		shad->delta = distance;
}
