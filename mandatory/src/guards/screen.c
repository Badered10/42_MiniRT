/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:03:13 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 20:41:27 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	*screen_res_guard(char **split, int line)
{
	if (split_len(split) != 2)
		throw_error("Invalid screen width: ", line, NULL);
	scene()->screen_width = ft_atoi(split[1]);
	if (scene()->screen_width < 50 || scene()->screen_width > 1000)
	{
		scene()->screen_width = WIN_WIDTH;
	}
	return (&scene()->screen_width);
}
