/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:16:20 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 19:34:00 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	insert_ambient_light(t_tambient_light *a_light)
{
	t_tambient_light	*a_light_node;

	a_light_node = scene()->ambient_light_list;
	if (!a_light_node)
	{
		scene()->ambient_light_list = a_light;
		return ;
	}
	while (a_light_node->next)
		a_light_node = a_light_node->next;
	a_light_node->next = a_light;
}

void	insert_cylinder(t_cylinder *cylinder)
{
	t_cylinder	*cylinder_node;

	cylinder_node = scene()->cylinder_list;
	if (!cylinder_node)
	{
		scene()->cylinder_list = cylinder;
		return ;
	}
	while (cylinder_node->next)
		cylinder_node = cylinder_node->next;
	cylinder_node->next = cylinder;
}

void	insert_plane(t_plane *plane)
{
	t_plane	*plane_node;

	plane_node = scene()->plane_list;
	if (!plane_node)
	{
		scene()->plane_list = plane;
		return ;
	}
	while (plane_node->next)
		plane_node = plane_node->next;
	plane_node->next = plane;
}

void	insert_sphere(t_sphere *sphere)
{
	t_sphere	*sphere_node;

	sphere_node = scene()->sphere_list;
	if (!sphere_node)
	{
		scene()->sphere_list = sphere;
		return ;
	}
	while (sphere_node->next)
		sphere_node = sphere_node->next;
	sphere_node->next = sphere;
}

void	insert_light(t_light *light)
{
	t_light	*light_node;

	light_node = scene()->light_list;
	if (!light_node)
	{
		scene()->light_list = light;
		return ;
	}
	while (light_node->next)
		light_node = light_node->next;
	light_node->next = light;
}
