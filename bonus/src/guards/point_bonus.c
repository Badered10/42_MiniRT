/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:03:07 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 23:29:30 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	point_guard(char *str, int line, double min, double max)
{
	t_vec3	res;
	char	**split;

	split = ft_split(str, ",");
	if (split_len(split) != 3)
		throw_error("Invalid point arguments at line: ", line, str);
	res.x = double_guard(split[0], line, min, max);
	res.y = double_guard(split[1], line, min, max);
	res.z = double_guard(split[2], line, min, max);
	return (res);
}
