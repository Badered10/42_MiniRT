/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:07:05 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 06:21:59 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	**mlx(void)
{
	static void	*mlx = NULL;

	return (&mlx);
}

void	**mlx_win(void)
{
	static void	*win = NULL;

	return (&win);
}

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

void	flush(void)
{
	mlx_put_image_to_window(*mlx(), *mlx_win(), data()->img, 0, 0);
}
