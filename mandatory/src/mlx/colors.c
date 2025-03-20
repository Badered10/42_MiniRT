/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:06:12 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:51:22 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_color	from_hex(int hex)
{
	t_color	res;

	res.r = ((hex >> 16) & 0xFF);
	res.g = ((hex >> 8) & 0xFF);
	res.b = (hex & 0xFF);
	return (res);
}

int	to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	t_coloro_hex(t_color *color)
{
	return (to_hex(color->r, color->g, color->b));
}

t_colord	t_coloro_double(t_color *color)
{
	t_colord	c;

	c.r = color->r / 255.0;
	c.g = color->g / 255.0;
	c.b = color->b / 255.0;
	return (c);
}

t_color	rgbd(double r, double g, double b)
{
	t_color	c;

	c.r = r * 255;
	c.g = g * 255;
	c.b = b * 255;
	return (c);
}
