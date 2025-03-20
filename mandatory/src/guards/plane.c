/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:40:04 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:51:39 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
 * identifier: pl
 * position of center: 0.0,0.0,-10.0
 * normalized orientation vector: 0.0,1.0,0.0
 * color: 0,0,225
 */
t_plane	*plane_guard(char **split, int line)
{
	t_plane	*res;

	if (split_len(split) != 4)
		throw_error("Invalid plane arguments at line: ", line, NULL);
	res = new_(sizeof(t_plane));
	res->pos = point_guard(split[1], line, DOUBLE_MIN, DOUBLE_MAX);
	res->normal = point_guard(split[2], line, -1, 1);
	res->color = color_guard(split[3], line);
	res->next = NULL;
	res->type = PLANE;
	insert_plane(res);
	return (res);
}
