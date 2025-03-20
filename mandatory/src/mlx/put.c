/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:07:11 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 01:04:03 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_pixel(int x, int y, int color)
{
	char	*dst;

	dst = data()->addr + (y * data()->line_length + x * (data()->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}
