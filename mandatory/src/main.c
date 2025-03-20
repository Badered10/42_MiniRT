/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:21:23 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:53:02 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ac_guard(int ac)
{
	if (ac < 2)
	{
		ft_putstr_fd("Missing arguments\n", 2);
		exit(1);
	}
}

void	init(void)
{
	char	*title;

	title = ft_strjoin(ft_strjoin(ft_strjoin(ft_itoa(scene()->screen_width),
					"x"), ft_itoa(scene()->screen_height)), ft_strjoin(" ",
				WIN_TITLE));
	*mlx() = mlx_init();
	*mlx_win() = mlx_new_window(*mlx(), scene()->screen_width,
		scene()->screen_height, title);
	data()->img = mlx_new_image(*mlx(), scene()->screen_width,
		scene()->screen_height);
	data()->addr = mlx_get_data_addr(data()->img, &data()->bits_per_pixel,
		&data()->line_length, &data()->endian);
}

int	main(int ac, char **av)
{
	double	aspect_ratio;

	ft_bzero(scene(), sizeof(t_scene *));
	scene()->screen_width = WIN_WIDTH;
	ac_guard(ac);
	read_map_data(av[1]);
	if (!scene()->camera)
	{
		throw_error("No camera found in the scene", -1, NULL);
	}
	aspect_ratio = 16.0 / 9.0;
	scene()->screen_height = scene()->screen_width / aspect_ratio;
	if (scene()->screen_height < 1)
		scene()->screen_height = 1;
	init();
	render();
	flush();
	events();
	mlx_loop((*mlx()));
	return (0);
}
