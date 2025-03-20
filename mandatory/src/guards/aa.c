/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:01:26 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:23:39 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	*anti_aliasing_guard(char **split, int line)
{
	if (split_len(split) != 2)
		throw_error("Invalid AA arguments at line: ", line, NULL);
	scene()->aa_round = ft_atoi(split[1]);
	if (scene()->aa_round < 0 || scene()->aa_round > 100)
		throw_error("Invalid AA round in line: ", line, split[1]);
	return (&scene()->aa_round);
}
