/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:06:40 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/17 19:52:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	scale_diameter(t_object *obj, double scale_factor, bool mod)
{
	if (obj->type == SPHERE)
		((t_sphere *)obj->shape)->diameter *= scale_factor;
	else if (obj->type == CONE)
	{
		if (mod)
			((t_cone *)obj->shape)->height *= scale_factor;
		else
			((t_cone *)obj->shape)->diameter *= scale_factor;
	}
	else if (obj->type == CYLINDER)
	{
		if (mod)
			((t_cylinder *)obj->shape)->diameter *= scale_factor;
		else
			((t_cylinder *)obj->shape)->height *= scale_factor;
	}
}
