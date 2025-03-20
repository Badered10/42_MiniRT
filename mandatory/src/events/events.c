/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:38:16 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 19:29:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	event_mapper(int keycode)
{
	bool		render_flag;
	t_object	*obj;

	obj = scene()->obj_to_move;
	render_flag = false;
	if (keycode == ESC)
		safe_close(0);
	else
		move_maper(keycode, &render_flag);
	if (obj)
	{
		if (keycode == BACKSPACE)
		{
			delete_(obj);
			obj = NULL;
			render_flag = true;
		}
	}
	if (render_flag)
	{
		render();
		flush();
	}
	return (0);
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

void	light_selecter(void)
{
	void		*light;
	static bool	selected;

	selected = !selected;
	if (selected)
	{
		light = scene()->light_list;
		scene()->obj_to_move = new_(sizeof(t_object));
		if (!scene()->obj_to_move)
			throw_error("Fatal, malloc fail to allocate", -1, NULL);
		scene()->obj_to_move->shape = light;
		scene()->obj_to_move->type = LIGHT;
		return ;
	}
	delete_(scene()->obj_to_move);
	scene()->obj_to_move = NULL;
}

int	mouse_hook(int btn, int x, int y, void *param)
{
	t_object	*obj;

	(void)param;
	obj = NULL;
	if (btn == 1 || btn == 3)
		obj = objects_selecter(btn, x, y);
	else if (btn == 2)
		light_selecter();
	if (obj)
	{
		render();
		flush();
	}
	return (0);
}

int	events(void)
{
	mlx_mouse_hook(*mlx_win(), mouse_hook, NULL);
	mlx_key_hook(*mlx_win(), event_mapper, NULL);
	mlx_hook(*mlx_win(), 17, 0, safe_close, 0);
	return (0);
}
