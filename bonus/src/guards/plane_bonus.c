/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:02:58 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 23:31:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
 * identifier: pl
 * position of center: 0.0,0.0,-10.0
 * normalized orientation vector: 0.0,1.0,0.0
 * color: 0,0,225
 * CheckerBoard existence :ck
 * |if ck founded next must be| color: 0,255,0
 */
t_plane	*plane_guard(char **split, int line)
{
	t_plane	*res;
	int		len;

	len = split_len(split);
	if (len != 4 && len != 6)
		throw_error("Invalid plane arguments at line: ", line, NULL);
	if (len == 6 && strcmp(split[4], "ck"))
		throw_error("Invalid plane arguments at line: ", line, NULL);
	res = new_(sizeof(t_plane));
	res->ck = 0;
	if (len == 6)
		res->ck = 1;
	res->pos = point_guard(split[1], line, DOUBLE_MIN, DOUBLE_MAX);
	res->normal = point_guard(split[2], line, -1, 1);
	res->color = color_guard(split[3], line);
	if (res->ck)
	{
		res->ck_colors[0] = res->color;
		res->ck_colors[1] = color_guard(split[5], line);
	}
	res->next = NULL;
	res->type = PLANE;
	insert_plane(res);
	return (res);
}
