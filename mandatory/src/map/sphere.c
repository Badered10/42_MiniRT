/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:16:15 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:53:14 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_sphere	*get_closest_sphere(t_ray *ray, double *closest_t)
{
	t_sphere	*closest_sphere;
	t_sphere	*sphere;
	double		t;

	sphere = scene()->sphere_list;
	closest_sphere = NULL;
	while (sphere)
	{
		t = instersect_sphere(ray, sphere);
		if (t > 0 && t < *closest_t)
		{
			*closest_t = t;
			closest_sphere = sphere;
		}
		sphere = sphere->next;
	}
	return (closest_sphere);
}
