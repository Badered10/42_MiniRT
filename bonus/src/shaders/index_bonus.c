/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:51:23 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 06:08:05 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static
t_color	texture_(t_dim *tex, t_vec3 *point, t_vec3 *normal, void *closest_obj)
{
	t_color	tex_color;

	tex_color = from_hex(texture_pixel(
				((t_sphere *)closest_obj)->texture, tex->w, tex->h));
	return (shaded_color(point, normal, &tex_color, ((t_sphere *)closest_obj)));
}

static
t_color	sphere(t_ray *ray, void *closest_obj, double closest_t)
{
	t_vec3	point;
	t_vec3	normal;
	t_vec2	uv;
	t_dim	tex;
	t_vec3	local_point;

	point = sum_(ray->origin, mult_(ray->direction, closest_t));
	normal = sub_(point, ((t_sphere *)closest_obj)->pos);
	norm_(&normal);
	if (((t_sphere *)closest_obj)->texture != NULL)
	{
		local_point = sub_(point, ((t_sphere *)closest_obj)->pos);
		norm_(&local_point);
		uv.x = 0.5 + atan2(local_point.z, local_point.x) / (2 * M_PI);
		uv.y = 0.5 - asin(local_point.y) / M_PI;
		tex.w = uv.x * ((t_sphere *)closest_obj)->texture->size.w;
		tex.h = uv.y * ((t_sphere *)closest_obj)->texture->size.h;
		return (texture_(&tex, &point, &normal, closest_obj));
	}
	return (shaded_color(&point, &normal,
			&((t_sphere *)closest_obj)->color, ((t_sphere *)closest_obj)));
}

static
t_color	plane(t_ray *ray, void *closest_obj, double closest_t)
{
	t_vec3	point;
	t_vec3	normal;

	point = sum_(ray->origin, mult_(ray->direction, closest_t));
	normal = ((t_plane *)closest_obj)->normal;
	if (dot_(ray->direction, normal) > 0)
		normal = mult_(normal, -1);
	return (shaded_color(&point, &normal,
			&((t_plane *)closest_obj)->color, ((t_plane *)closest_obj)));
}

t_color	color_shader(void *closest_obj, double closest_t, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	if (((t_object *)closest_obj)->type == SPHERE)
		return (sphere(ray, closest_obj, closest_t));
	else if (((t_object *)closest_obj)->type == PLANE)
		return (plane(ray, closest_obj, closest_t));
	else if (((t_object *)closest_obj)->type == CYLINDER)
	{
		point = sum_(ray->origin, mult_(ray->direction, closest_t));
		normal = sub_(point, ((t_cylinder *)closest_obj)->pos);
		norm_(&normal);
		return (shaded_color(&point, &normal,
				&((t_cylinder *)closest_obj)->color,
				((t_cylinder *)closest_obj)));
	}
	else if (((t_object *)closest_obj)->type == CONE)
	{
		point = sum_(ray->origin, mult_(ray->direction, closest_t));
		normal = sub_(point, ((t_cone *)closest_obj)->pos);
		norm_(&normal);
		return (shaded_color(&point, &normal,
				&((t_cone *)closest_obj)->color, ((t_cone *)closest_obj)));
	}
	return (from_hex(0));
}
