/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:49 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 06:07:58 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_plane	*get_closest_plane(t_ray *ray, double *closest_t)
{
	t_plane	*closest_plane;
	t_plane	*plane;
	double	t;

	closest_plane = NULL;
	plane = scene()->plane_list;
	while (plane)
	{
		t = intersect_plane(ray, plane);
		if (t > 0 && t < *closest_t)
		{
			*closest_t = t;
			closest_plane = plane;
		}
		plane = plane->next;
	}
	return (closest_plane);
}
