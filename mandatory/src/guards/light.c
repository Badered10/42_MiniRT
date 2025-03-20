/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:02:49 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:50:11 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
	* A 0.2 255,255,255
	∗ identifier: A
	∗ ambient lighting ratio in range [0.0,1.0]: 0.2
	∗ R,G,B colors in range [0-255]: 255, 255, 255

	* L -40.0,50.0,0.0 0.6 10,0,255
	∗ identifier: L
	∗ x,y,z coordinates of the light source: -40.0, 50.0, 0.0
	∗ the light brightness ratio in range [0.0,1.0]: 0.6
	∗ R,G,B colors in range [0-255]: 10, 0, 255
 */
t_tambient_light	*ambient_lighting_guard(char **split, int line)
{
	double				lighting_ratio;
	t_tambient_light	*res;
	t_color				color;

	if (split_len(split) != 3)
		throw_error("Invalid arguments of ambient light in line: ", line, NULL);
	lighting_ratio = double_guard(split[1], line, 0, 1);
	(void)lighting_ratio;
	color = color_guard(split[2], line);
	res = new_(sizeof(t_tambient_light));
	res->lighting_ratio = lighting_ratio;
	res->color.r = color.r;
	res->color.g = color.g;
	res->color.b = color.b;
	res->next = NULL;
	insert_ambient_light(res);
	return (res);
}

t_light	*light_guard(char **split, int line)
{
	t_light	*res;

	if (split_len(split) != 4)
		throw_error("Invalid light arguments at line: ", line, NULL);
	res = new_(sizeof(t_light));
	res->pos = point_guard(split[1], line, DOUBLE_MIN, DOUBLE_MAX);
	res->brightness = double_guard(split[2], line, 0, 1);
	res->color = color_guard(split[3], line);
	res->next = NULL;
	insert_light(res);
	return (res);
}
