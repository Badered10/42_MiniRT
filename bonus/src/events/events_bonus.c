/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:38:16 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/19 09:29:43 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	safe_close(int ntn)
{
	(void)ntn;
	pthread_mutex_lock(&sys_data()->close_lock);
	clean_();
	if (*mlx())
	{
		if (data())
			mlx_destroy_image(*mlx(), data()->img);
		if (*mlx_win())
			mlx_destroy_window(*mlx(), *mlx_win());
		mlx_destroy_display(*mlx());
		free(*mlx());
	}
	pthread_mutex_unlock(&sys_data()->close_lock);
	exit(0);
	return (0);
}

void	light_selecter(int btn)
{
	if (scene()->light_selected)
	{
		if (!scene()->light_target)
			scene()->light_target = scene()->light_list;
		else if (btn == 9)
			scene()->light_target = scene()->light_target->next;
		else if (btn == 8)
			scene()->light_target = scene()->light_target->prev;
		if (scene()->light_target)
		{
			scene()->obj_to_move = new_(sizeof(t_object));
			scene()->obj_to_move->shape = scene()->light_target;
			scene()->obj_to_move->type = LIGHT;
		}
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
	{
		obj = objects_selecter(btn, x, y);
		if (obj)
			sys_data()->full_render = false;
	}
	else if (btn == 9 || btn == 8)
		light_selecter(btn);
	if (obj)
		render_scene();
	flush();
	return (0);
}

int	events(void)
{
	mlx_mouse_hook(*mlx_win(), mouse_hook, NULL);
	mlx_key_hook(*mlx_win(), event_mapper, NULL);
	mlx_hook(*mlx_win(), 17, 0, safe_close, 0);
	return (0);
}
