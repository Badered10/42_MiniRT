/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:00:26 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 23:27:26 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_all_digits(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
	}
	return (0);
}

t_color	color_guard(char *color, int line)
{
	char	**color_idents;
	int		color_value;
	int		i;
	t_color	color_return ;

	color_idents = ft_split(color, ",");
	i = 0;
	ft_bzero(&color_return, sizeof(t_color));
	while (color_idents[i])
	{
		if (i > 2 || check_all_digits(color_idents[i]))
			throw_error("Unrespected RGB syntax at line: ", line, color);
		color_value = ft_atoi(color_idents[i]);
		if (color_value > 255 || color_value < 0)
			throw_error("Invalid color value [0, 255] in line: ", line,
				color_idents[i]);
		if (i == 0)
			color_return.r = color_value;
		if (i == 1)
			color_return.g = color_value;
		if (i == 2)
			color_return.b = color_value;
		i++;
	}
	return (color_return);
}
