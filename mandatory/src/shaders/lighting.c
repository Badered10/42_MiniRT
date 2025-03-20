/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 03:51:48 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 07:55:52 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	effect_shadow(t_shadow *shad)
{
	t_vec3	inters_point;
	double	distance;

	shad->shadow_ray.t = shad->t;
	inters_point = ray_point(&shad->shadow_ray);
	distance = sqrt(dot_(sub_(inters_point, shad->shadow_origin),
				sub_(inters_point, shad->shadow_origin)));
	if (distance < shad->distance_to_light && distance > shad->delta)
		shad->delta = distance;
}
