/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 04:45:45 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:03:51 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	ambient_light(void)
{
	if (scene()->ambient_light_list)
		return (scene()->ambient_light_list->lighting_ratio);
	return (.3);
}

double	diffuse_light(t_vec3 *normal, t_vec3 *light_vec, double brightness,
		double distance)
{
	return (fmax(dot_(*normal, *light_vec), 0.0) * brightness / distance);
}

t_color	shade_sphere_plane(t_object *closest_obj, t_vec3 point)
{
	t_vec3	normal;

	if (((t_object *)closest_obj)->type == SPHERE)
	{
		normal = sub_(point, ((t_sphere *)closest_obj)->pos);
		norm_(&normal);
		return (shaded_color(&point, &normal, &((t_sphere *)closest_obj)->color,
				((t_sphere *)closest_obj)));
	}
	else
	{
		normal = ((t_plane *)closest_obj)->normal;
		return (shaded_color(&point, &normal, &((t_plane *)closest_obj)->color,
				((t_plane *)closest_obj)));
	}
}

t_color	shade_cylinder_cone(t_object *closest_obj, t_vec3 point)
{
	t_vec3	normal;

	if (((t_object *)closest_obj)->type == CYLINDER)
	{
		normal = sub_(point, ((t_cylinder *)closest_obj)->pos);
		norm_(&normal);
		return (shaded_color(&point, &normal,
				&((t_cylinder *)closest_obj)->color,
				((t_cylinder *)closest_obj)));
	}
	else
	{
		normal = sub_(point, ((t_cone *)closest_obj)->pos);
		norm_(&normal);
		return (shaded_color(&point, &normal, &((t_cone *)closest_obj)->color,
				((t_cone *)closest_obj)));
	}
}

t_color	color_shader(void *closest_obj, double closest_t, t_ray *ray)
{
	t_vec3	point;
	int8_t	type;

	point = sum_(ray->origin, mult_(ray->direction, closest_t));
	type = ((t_object *)closest_obj)->type;
	if (type == SPHERE || type == PLANE)
		return (shade_sphere_plane(closest_obj, point));
	else if (type == CYLINDER || type == CONE)
		return (shade_cylinder_cone(closest_obj, point));
	return (from_hex(0x262626));
}
