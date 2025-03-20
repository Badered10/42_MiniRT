/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:10:46 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	cross_(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

double	dot_(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

void	norm_(t_vec3 *v)
{
	double	magnitude;

	magnitude = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x /= magnitude;
	v->y /= magnitude;
	v->z /= magnitude;
}

void	normalize(t_vec3 *v)
{
	double	magnitude;

	magnitude = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x /= magnitude;
	v->y /= magnitude;
	v->z /= magnitude;
}
