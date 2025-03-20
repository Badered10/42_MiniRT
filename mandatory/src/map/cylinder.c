/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:13:17 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:53:14 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_cylinder	*get_closest_cylinder(t_ray *ray, double *closest_t)
{
	t_cylinder	*closest_cylinder;
	t_cylinder	*cylinder;
	double		t;

	closest_cylinder = NULL;
	cylinder = scene()->cylinder_list;
	while (cylinder)
	{
		t = intersect_cylinder(ray, cylinder);
		if (t > 0 && t < *closest_t)
		{
			*closest_t = t;
			closest_cylinder = cylinder;
		}
		cylinder = cylinder->next;
	}
	return (closest_cylinder);
}
