/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:13:02 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:53:14 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_cone	*get_closest_cone(t_ray *ray, double *closest_t)
{
	t_cone	*closest_cone;
	t_cone	*cone;
	double	t;

	closest_cone = NULL;
	cone = scene()->cone_list;
	while (cone)
	{
		t = intersect_cone(ray, cone);
		if (t > 0 && t < *closest_t)
		{
			*closest_t = t;
			closest_cone = cone;
		}
		cone = cone->next;
	}
	return (closest_cone);
}
