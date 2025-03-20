/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:02:41 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 03:26:55 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
		arccos( ( (CD^2) + (CP^2) - (PD ^ 2) ) / (2 * CD * CP) )
*/
double	dist(t_vec3 *p1, t_vec3 *p2)
{
	return (sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z
				- p1->z, 2)));
}

bool	is_in_fov(t_vec3 *center)
{
	double		angle_between;
	t_camera	*camera;

	camera = scene()->camera;
	angle_between = acos((pow(dist(&camera->pos, &camera->direction), 2)
				+ pow(dist(&camera->pos, center), 2) - pow(dist(center,
						&camera->direction), 2)) / (2 * dist(&camera->pos,
					&camera->direction) * dist(&camera->pos, center)));
	angle_between *= 180 / M_PI;
	if (angle_between < (camera->fov / 2))
		return (true);
	return (false);
}
