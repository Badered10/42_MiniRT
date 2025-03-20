/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:23:25 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 03:26:10 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init(void)
{
	char	*title;

	if (!XInitThreads())
	{
		throw_error("Failed to initialize X11 threading", -1, NULL);
		exit(1);
	}
	title = ft_strjoin(ft_strjoin(ft_strjoin(ft_itoa(sys_data()->screen_width),
					"x"), ft_itoa(sys_data()->screen_height)), ft_strjoin(" ",
				WIN_TITLE));
	*mlx() = mlx_init();
	*mlx_win() = mlx_new_window(*mlx(), sys_data()->screen_width,
		sys_data()->screen_height, title);
	data()->img = mlx_new_image(*mlx(), sys_data()->screen_width,
		sys_data()->screen_height);
	data()->addr = mlx_get_data_addr(data()->img, &data()->bits_per_pixel,
		&data()->line_length, &data()->endian);
}

void	ac_guard(int ac)
{
	if (ac < 2)
	{
		ft_putstr_fd("Missing arguments\n", 2);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	double	aspect_ratio;

	ft_bzero(scene(), sizeof(t_scene *));
	ft_bzero(sys_data(), sizeof(t_sys_data *));
	pthread_mutex_init(&sys_data()->gc_lock, NULL);
	pthread_mutex_init(&sys_data()->close_lock, NULL);
	sys_data()->screen_width = WIN_WIDTH;
	sys_data()->cpu_cores = sysconf(_SC_NPROCESSORS_ONLN) * 2;
	if (sys_data()->cpu_cores < 1)
		throw_error("Error reading CPU information!", -1, NULL);
	ac_guard(ac);
	read_map_data(av[1]);
	if (!scene()->camera)
		throw_error("No camera found in the scene", -1, NULL);
	aspect_ratio = 16.0 / 9.0;
	sys_data()->screen_height = sys_data()->screen_width / aspect_ratio;
	if (sys_data()->screen_height < 1)
		sys_data()->screen_height = 1;
	init();
	apply_textures();
	render_scene();
	events();
	flush();
	mlx_loop((*mlx()));
	return (0);
}
