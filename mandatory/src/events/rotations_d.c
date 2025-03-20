/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:24:07 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:52:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	xd_hundler(void *shape, double angle, int type)
{
	if (type == CONE)
		((t_cone *)shape)->normal = rotate_x(((t_cone *)shape)->normal, angle);
	else if (type == CYLINDER)
		((t_cylinder *)shape)->normal = rotate_x(((t_cylinder *)shape)->normal,
				angle);
	else if (type == PLANE)
		((t_plane *)shape)->normal = rotate_x(((t_plane *)shape)->normal,
				angle);
}

void	yd_hundler(void *shape, double angle, int type)
{
	if (type == CONE)
		((t_cone *)shape)->normal = rotate_y(((t_cone *)shape)->normal, angle);
	else if (type == CYLINDER)
		((t_cylinder *)shape)->normal = rotate_y(((t_cylinder *)shape)->normal,
				angle);
	else if (type == PLANE)
		((t_plane *)shape)->normal = rotate_y(((t_plane *)shape)->normal,
				angle);
}

void	zd_hundler(void *shape, double angle, int type)
{
	if (type == CONE)
		((t_cone *)shape)->normal = rotate_z(((t_cone *)shape)->normal, angle);
	else if (type == CYLINDER)
		((t_cylinder *)shape)->normal = rotate_z(((t_cylinder *)shape)->normal,
				angle);
	else if (type == PLANE)
		((t_plane *)shape)->normal = rotate_z(((t_plane *)shape)->normal,
				angle);
}
