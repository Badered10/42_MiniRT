/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendered_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:16:04 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sphere_cylinder_hit(void **closest_obj, double *closest_t, t_ray *ray)
{
	void	*sphere;
	void	*cylinder;

	sphere = get_closest_sphere(ray, closest_t);
	if (sphere)
		*closest_obj = sphere;
	cylinder = get_closest_cylinder(ray, closest_t);
	if (cylinder)
		*closest_obj = cylinder;
}

void	cone_plane_hit(void **closest_obj, double *closest_t, t_ray *ray)
{
	void	*cone;
	t_plane	*plane;

	cone = get_closest_cone(ray, closest_t);
	if (cone)
		*closest_obj = cone;
	plane = get_closest_plane(ray, closest_t);
	if (plane)
		*closest_obj = plane;
}

t_color	trace_a_ray(t_ray *ray)
{
	double	closest_t;
	void	*closest_obj;

	closest_obj = NULL;
	closest_t = INFINITY;
	sphere_cylinder_hit(&closest_obj, &closest_t, ray);
	cone_plane_hit(&closest_obj, &closest_t, ray);
	if (!closest_obj)
		return (from_hex(0x262626));
	if (scene()->obj_to_move && scene()->obj_to_move->shape == closest_obj)
		return (((t_object *)closest_obj)->color);
	return (color_shader(closest_obj, closest_t, ray));
}

t_color	compute_pixel_color(t_vec3 pixel_center, t_render_range *rr_)
{
	t_vec3	direction;
	t_ray	ray;
	t_color	simple_color;

	direction = sub_(pixel_center, rr_->camera_center);
	if (scene()->aa_round > 0)
		add_(&direction, (rand() / (double)RAND_MAX - .001) * .003);
	norm_(&direction);
	ray.origin = rr_->camera_center;
	ray.direction = direction;
	simple_color = trace_a_ray(&ray);
	return (simple_color);
}
