/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:03:13 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 03:26:02 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	*screen_res_guard(char **split, int line)
{
	if (split_len(split) != 2)
		throw_error("Invalid screen width: ", line, NULL);
	sys_data()->screen_width = ft_atoi(split[1]);
	if (sys_data()->screen_width < 50 || sys_data()->screen_width > 2000)
	{
		sys_data()->screen_width = WIN_WIDTH;
	}
	return (&sys_data()->screen_width);
}
