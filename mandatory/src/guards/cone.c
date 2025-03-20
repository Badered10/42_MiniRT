/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:01:57 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:52:29 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * co 50.0,0.0,20.6 0.0,0.0,1.0 2 21.42 10,0,255
 * identifier: co
 * coordinates of the apex: 50.0,0.0,20.6
 * normalized orientation vector: 0.0,0.0,1.0 [-1, 1]
 * diameter: 2 [0, inf]
 * height: 21.42 [0, inf]
 * color: 10,0,255
 */
t_cone	*cone_guard(char **split, int line)
{
	t_cone	*res;

	if (split_len(split) != 6)
		throw_error("Invalid cone arguments at line: ", line, NULL);
	res = new_(sizeof(t_cone));
	res->pos = point_guard(split[1], line, DOUBLE_MIN, DOUBLE_MAX);
	res->normal = point_guard(split[2], line, -1, 1);
	res->diameter = double_guard(split[3], line, 0.1, DOUBLE_MAX);
	res->height = double_guard(split[4], line, 0.1, DOUBLE_MAX);
	res->color = color_guard(split[5], line);
	res->next = NULL;
	res->type = CONE;
	insert_cone(res);
	return (res);
}
