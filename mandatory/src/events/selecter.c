/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:33:47 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 20:57:35 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	safe_close(int ntn)
{
	(void)ntn;
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
	exit(0);
	return (0);
}

void	move_maper(int keycode, bool *render)
{
	if (scene()->obj_to_move)
		move_any(keycode, render);
	else
		camera_hundler(keycode, render);
	if (keycode == CTRL)
	{
		delete_(scene()->obj_to_move);
		scene()->obj_to_move = NULL;
		*render = true;
	}
}
