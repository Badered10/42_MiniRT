/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:44 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 06:07:58 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	compute_pattern(t_ray *ray, double closest_t, t_plane *plane)
{
	t_vec3	hit_point;
	t_vec3	right;
	t_vec3	up;
	t_vec3	local_point;

	hit_point = ray_at(ray, closest_t);
	if (fabs(plane->normal.x) > 0.9)
		right = cross_(plane->normal, (t_vec3){0, 1, 0});
	else
		right = cross_(plane->normal, (t_vec3){1, 0, 0});
	norm_(&right);
	up = cross_(right, plane->normal);
	norm_(&up);
	local_point.x = dot_(hit_point, right);
	local_point.y = dot_(hit_point, up);
	if (((int)round(local_point.x) + (int)round(local_point.y)) % 2)
	{
		plane->color = plane->ck_colors[1];
		return ;
	}
	plane->color = plane->ck_colors[0];
}
