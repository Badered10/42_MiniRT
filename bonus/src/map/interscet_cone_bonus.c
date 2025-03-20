/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interscet_cone_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:28 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 03:31:36 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	dis_cone(double *t, t_vec3 *v_w, double k, t_vec2 *dot)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;

	a = dot_(v_w[0], v_w[0]) - (k * (*dot).x * (*dot).x);
	b = 2.0 * (dot_(v_w[0], v_w[1]) - (k * (*dot).x * (*dot).y));
	c = dot_(v_w[1], v_w[1]) - (k * (*dot).y * (*dot).y);
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant < 0)
		return (-1);
	t[0] = (-b - sqrt(discriminant)) / (2.0 * a);
	t[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	return (0);
}

int	compute_cone(double *t, t_vec3 *v_w, double radius, t_vec2 *dot)
{
	double	k;

	k = radius * radius;
	return (dis_cone(t, v_w, k, dot));
}

int	cal_cone_space(double *t, t_vec2 *dot, t_ray *ray, t_cone *cone)
{
	t_vec3	oc;
	double	radius_height_ratio;
	t_vec3	v_w[2];

	oc = sub_(ray->origin, cone->pos);
	radius_height_ratio = (cone->diameter / 2.0) / cone->height;
	(*dot).x = dot_(ray->direction, cone->normal);
	(*dot).y = dot_(oc, cone->normal);
	v_w[0] = sub_(ray->direction, mult_(cone->normal, (*dot).x));
	v_w[1] = sub_(oc, mult_(cone->normal, (*dot).y));
	return (compute_cone(t, v_w, radius_height_ratio, dot));
}

double	valid_t_cone(double *t, double *h, t_cone *cone)
{
	double	res;

	res = -1.0;
	if (t[0] > EPSILON && h[0] >= 0 && h[0] <= cone->height)
		res = t[0];
	if (t[1] > EPSILON && h[1] >= 0 && h[1] <= cone->height)
		res = t[1];
	return (res);
}

double	intersect_cone(t_ray *ray, t_cone *cone)
{
	t_vec2	dot;
	double	h[2];
	double	t[2];

	if (cal_cone_space(t, &dot, ray, cone))
		return (-1);
	h[0] = dot.y + t[0] * dot.x;
	h[1] = dot.y + t[1] * dot.x;
	return (valid_t_cone(t, h, cone));
}
