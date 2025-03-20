/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:54 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	ray_at(t_ray *ray, double closest_t)
{
	t_vec3	pose;
	t_vec3	a_move;

	if (!ray)
		return ((t_vec3){0, 0, 0});
	a_move = mult_(ray->direction, closest_t);
	pose = sum_(ray->origin, a_move);
	return (pose);
}

t_ray	*create_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	*ray;

	ray = new_(sizeof(t_ray));
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}

t_vec3	ray_point(t_ray *ray)
{
	return (sum_(ray->origin, mult_(ray->direction, ray->t)));
}
