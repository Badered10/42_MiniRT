/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:54 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 06:07:58 by abchikhi         ###   ########.fr       */
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

// ray(t) = origin + t * direction
t_vec3	ray_point(t_ray *ray)
{
	return (sum_(ray->origin, mult_(ray->direction, ray->t)));
}
