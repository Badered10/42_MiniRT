/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_others_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:39 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 06:07:58 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	compute_sphere(double a, double b, double radius, t_vec3 oc)
{
	double	discriminant;
	double	c;
	double	t1;
	double	t2;

	c = dot_(oc, oc) - (radius * radius);
	discriminant = (b * b) - 4 * a * c;
	if (discriminant < 0)
		return (false);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	if (t1 > EPSILON)
		return (t1);
	if (t2 > EPSILON)
		return (t2);
	return (-1);
}

double	instersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	radius;

	oc = sub_(ray->origin, sphere->pos);
	a = dot_(ray->direction, ray->direction);
	b = 2.0 * dot_(oc, ray->direction);
	radius = sphere->diameter / 2.0;
	return (compute_sphere(a, b, radius, oc));
}

double	intersect_plane(t_ray *ray, t_plane *plane)
{
	t_vec3	op;
	double	nop;
	double	nd;

	op = sub_(plane->pos, ray->origin);
	nop = dot_(plane->normal, op);
	nd = dot_(plane->normal, ray->direction);
	return (nop / nd);
}
