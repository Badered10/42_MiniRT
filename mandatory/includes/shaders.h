/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:48:34 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 23:09:56 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADERS_H
# define SHADERS_H

typedef struct shadow_s
{
	double	t;
	double	distance;
	double	distance_to_light;
	double	delta;
	t_vec3	light_vec;
	t_vec3	shadow_origin;
	t_ray	shadow_ray;
	double	shin;
}	t_shadow;

t_color	color_shader(void *closest_obj, double closest_t, t_ray *ray);

double	ambient_light(void);
double	diffuse_light(t_vec3 *normal, t_vec3 *light_vec, double brightness,
			double distance);

// shader.c
t_color	shaded_color(t_vec3 *point, t_vec3 *normal, t_color *plane_color,
			void *self);

void	effect_shadow(t_shadow *shad);

#endif