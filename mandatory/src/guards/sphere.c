/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:40:52 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:49:56 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * sp 0.0,0.0,20.6 12.6 10,0,255
 * identifier: sp
 * position of center: 0.0,0.0,20.6
 * diameter: 12.6
 * color: 10,0,255
 */
t_sphere	*sphere_guard(char **split, int line_count)
{
	t_sphere	*res;

	if (split_len(split) != 4)
		throw_error("Invalid sphere arguments at line: ", line_count, NULL);
	res = new_(sizeof(t_sphere));
	res->pos = point_guard(split[1], line_count, DOUBLE_MIN, DOUBLE_MAX);
	res->diameter = double_guard(split[2], line_count, 0.1, DOUBLE_MAX);
	res->color = color_guard(split[3], line_count);
	res->next = NULL;
	res->type = SPHERE;
	insert_sphere(res);
	return (res);
}
