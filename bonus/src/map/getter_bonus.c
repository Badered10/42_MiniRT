/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:15:22 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 06:08:13 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_scene	*scene(void)
{
	static t_scene	scene_;

	return (&scene_);
}

t_sys_data	*sys_data(void)
{
	static t_sys_data	system_data;

	return (&system_data);
}
