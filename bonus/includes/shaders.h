/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:35:33 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 07:57:02 by abchikhi         ###   ########.fr       */
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
	double	rand;
}			t_shadow;

t_color		color_shader(void *closest_obj, double closest_t, t_ray *ray);

double		ambient_light(void);
double		diffuse_light(t_vec3 *normal, t_vec3 *light_vec, double brightness,
				double distance);
double		specular_light(t_vec3 *point, t_vec3 *normal, t_light *l);

t_color		shaded_color(t_vec3 *point, t_vec3 *normal, t_color *obj_color,
				void *self);

void		effect_shadow(t_shadow *shad);

#endif
