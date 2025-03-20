/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:09:44 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ray	ray_one(t_render_range *rr_, int x, int y)
{
	t_vec3	pixel_center;
	t_vec3	direction;
	t_ray	ray;

	pixel_center = sum_(rr_->viewport_upper_left, sum_(mult_(rr_->h_pixel_delta,
					x), mult_(rr_->v_pixel_delta, y)));
	direction = sub_(pixel_center, rr_->camera_center);
	if (scene()->aa_round > 0)
		add_(&direction, (rand() / (double)RAND_MAX - .001) * .003);
	norm_(&direction);
	ray.origin = rr_->camera_center;
	ray.direction = direction;
	delete_(rr_);
	return (ray);
}

t_ray	do_ray(double x, double y)
{
	t_render_range	*range;

	range = new_(sizeof(t_render_range));
	calc_scene(range);
	return (ray_one(range, x, y));
}

static void	closest_sphere_cylinder(t_object *closest_obj, double *closest_t,
		t_ray *ray)
{
	t_sphere	*sphere;
	void		*cylinder;

	sphere = get_closest_sphere(ray, closest_t);
	if (sphere)
	{
		closest_obj->shape = sphere;
		closest_obj->type = SPHERE;
	}
	cylinder = get_closest_cylinder(ray, closest_t);
	if (cylinder)
	{
		closest_obj->shape = cylinder;
		closest_obj->type = CYLINDER;
	}
}

static void	closest_cone_plane(t_object *closest_obj, double *closest_t,
		t_ray *ray)
{
	void	*cone;
	t_plane	*plane;

	cone = get_closest_cone(ray, closest_t);
	if (cone)
	{
		closest_obj->shape = cone;
		closest_obj->type = CONE;
	}
	plane = get_closest_plane(ray, closest_t);
	if (plane)
	{
		closest_obj->shape = plane;
		closest_obj->type = PLANE;
	}
}

t_object	*closest_obj(t_ray *ray)
{
	double		closest_t;
	t_object	*closest_obj;

	closest_obj = new_(sizeof(t_object));
	closest_obj->type = -1;
	closest_t = INFINITY;
	closest_sphere_cylinder(closest_obj, &closest_t, ray);
	closest_cone_plane(closest_obj, &closest_t, ray);
	if (closest_obj->type == -1)
		return (delete_(closest_obj), NULL);
	return (closest_obj);
}
