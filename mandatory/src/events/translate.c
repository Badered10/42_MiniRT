/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:05:40 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	trans_ps(t_object *obj, t_vec3 translation_vector)
{
	if (obj->type == PLANE)
	{
		((t_plane *)obj->shape)->pos.x += translation_vector.x;
		((t_plane *)obj->shape)->pos.y += translation_vector.y;
		((t_plane *)obj->shape)->pos.z += translation_vector.z;
	}
	else if (obj->type == SPHERE)
	{
		((t_sphere *)obj->shape)->pos.x += translation_vector.x;
		((t_sphere *)obj->shape)->pos.y += translation_vector.y;
		((t_sphere *)obj->shape)->pos.z += translation_vector.z;
	}
}

void	trans_cs(t_object *obj, t_vec3 translation_vector)
{
	if (obj->type == CONE)
	{
		((t_cone *)obj->shape)->pos.x += translation_vector.x;
		((t_cone *)obj->shape)->pos.y += translation_vector.y;
		((t_cone *)obj->shape)->pos.z += translation_vector.z;
	}
	else if (obj->type == CYLINDER)
	{
		((t_cylinder *)obj->shape)->pos.x += translation_vector.x;
		((t_cylinder *)obj->shape)->pos.y += translation_vector.y;
		((t_cylinder *)obj->shape)->pos.z += translation_vector.z;
	}
}

void	trans_light(t_object *obj, t_vec3 translation_vector)
{
	((t_light *)obj->shape)->pos.x += translation_vector.x;
	((t_light *)obj->shape)->pos.y += translation_vector.y;
	((t_light *)obj->shape)->pos.z += translation_vector.z;
}

void	translate_shape(t_object *obj, t_vec3 translation_vector)
{
	if (!obj)
		return ;
	if (obj->type == PLANE || obj->type == SPHERE)
		trans_ps(obj, translation_vector);
	else if (obj->type == CONE || obj->type == CYLINDER)
		trans_cs(obj, translation_vector);
	else
		trans_light(obj, translation_vector);
}
