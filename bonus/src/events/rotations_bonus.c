/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:04:22 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 06:02:37 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	rotate_z(t_vec3 v, double angle)
{
	t_vec3	rotated;

	rotated.x = v.x * cos(angle) - v.y * sin(angle);
	rotated.y = v.x * sin(angle) + v.y * cos(angle);
	rotated.z = v.z;
	return (rotated);
}

t_vec3	rotate_x(t_vec3 v, double angle)
{
	t_vec3	rotated;

	rotated.x = v.x;
	rotated.y = v.y * cos(angle) - v.z * sin(angle);
	rotated.z = v.y * sin(angle) + v.z * cos(angle);
	return (rotated);
}

t_vec3	rotate_y(t_vec3 v, double angle)
{
	t_vec3	rotated;

	rotated.x = v.x * cos(angle) + v.z * sin(angle);
	rotated.y = v.y;
	rotated.z = -v.x * sin(angle) + v.z * cos(angle);
	return (rotated);
}

void	rotate_shape(void *shape, double angle, int type, int axis)
{
	if (axis == X_AXIS)
		xd_hundler(shape, angle, type);
	else if (axis == Y_AXIS)
		yd_hundler(shape, angle, type);
	else if (axis == Z_AXIS)
		zd_hundler(shape, angle, type);
}
