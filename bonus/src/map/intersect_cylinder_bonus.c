/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:33 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 06:22:58 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	do_dis(t_vec3 v_w[], double radius, double *t)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = dot_(v_w[0], v_w[0]);
	b = 2.0 * dot_(v_w[0], v_w[1]);
	c = dot_(v_w[1], v_w[1]) - (radius * radius);
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant < 0)
		return (-1);
	t[0] = (-b - sqrt(discriminant)) / (2.0 * a);
	t[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	return (1);
}

int	compute_cylinder(t_vec3 v_w[], double radius, double *t)
{
	if (do_dis(v_w, radius, t) == -1)
		return (-1);
	return (0);
}

int	cal_cyl_space(double *t, t_vec2 *dot, t_ray *ray, t_cylinder *cylinder)
{
	t_vec3	oc;
	double	radius;
	t_vec3	v_w[2];

	oc = sub_(ray->origin, cylinder->pos);
	radius = cylinder->diameter / 2.0;
	(*dot).y = dot_(ray->direction, cylinder->normal);
	(*dot).x = dot_(oc, cylinder->normal);
	v_w[0] = sub_(ray->direction, mult_(cylinder->normal, (*dot).y));
	v_w[1] = sub_(oc, mult_(cylinder->normal, (*dot).x));
	return (compute_cylinder(v_w, radius, t));
}

double	valid_t(double *t, double *y, t_cylinder *cylinder)
{
	double	res;

	res = -1.0;
	if (t[0] > EPSILON && y[0] >= -cylinder->height / 2.0
		&& y[0] <= cylinder->height / 2.0)
		res = t[0];
	else if (t[1] > EPSILON && y[1] >= -cylinder->height / 2.0
		&& y[1] <= cylinder->height / 2.0)
		res = t[1];
	return (res);
}

double	intersect_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_vec2	dot;
	double	t[2];
	double	y[2];

	if (cal_cyl_space(t, &dot, ray, cylinder) == -1)
		return (-1.0);
	y[0] = dot.x + t[0] * dot.y;
	y[1] = dot.x + t[1] * dot.y;
	return (valid_t(t, y, cylinder));
}
