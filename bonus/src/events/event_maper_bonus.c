/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_maper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:24:07 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 09:18:27 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_maper(int keycode, bool *render)
{
	sys_data()->full_render = false;
	if (scene()->obj_to_move)
		move_any(keycode, render);
	else
		camera_hundler(keycode, render);
	if (keycode == CTRL)
	{
		delete_(scene()->obj_to_move);
		scene()->obj_to_move = NULL;
		sys_data()->full_render = !sys_data()->full_render;
		*render = true;
	}
}

t_object	*objects_selecter(int btn, int x, int y)
{
	t_ray		ray;
	t_object	*obj;
	t_object	*set;

	set = NULL;
	obj = NULL;
	if (btn == 1 || btn == 3)
	{
		ray = do_ray(x, y);
		obj = closest_obj(&ray);
		if (!obj)
			return (NULL);
		set = obj;
	}
	if (btn == 3 && scene()->obj_to_move && obj
		&& scene()->obj_to_move->shape == obj->shape)
	{
		delete_(obj);
		set = NULL;
	}
	scene()->obj_to_move = set;
	return (obj);
}

int	event_mapper(int keycode)
{
	bool		render;

	render = false;
	if (keycode == SPACE)
		scene()->light_selected = !scene()->light_selected;
	else if (keycode == ESC)
		safe_close(0);
	else if (keycode == BACKSPACE && scene()->obj_to_move)
	{
		delete_(scene()->obj_to_move);
		scene()->obj_to_move = NULL;
		render = true;
	}
	else
		move_maper(keycode, &render);
	if (render)
	{
		render_scene();
		if (!sys_data()->full_render)
			flush();
	}
	return (0);
}
