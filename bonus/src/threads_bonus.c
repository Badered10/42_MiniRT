/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 01:36:50 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/19 09:21:40 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*render_thread(void *arg)
{
	t_render_range	*range;

	range = (t_render_range *)arg;
	calc_scene(range);
	render(range);
	delete_(range);
	return (NULL);
}

void	config_thread(t_dim *dim, int *thread_id,
int tile[], t_thread threads[])
{
	threads[*thread_id].range.x_range[0] = dim->w * tile[0];
	threads[*thread_id].range.x_range[1] = (dim->w + 1) * tile[0];
	threads[*thread_id].range.y_range[0] = dim->h * tile[1];
	threads[*thread_id].range.y_range[1] = (dim->h + 1) * tile[1];
	pthread_create(&threads[*thread_id].pid, NULL,
		render_thread, &(threads[*thread_id].range));
	(*thread_id)++;
}

void	launch_and_join(t_thread threads[], int thread_id,
int grid_size, int tile[])
{
	t_dim	dim;
	int		i;

	ft_bzero(&dim, sizeof(t_dim));
	while (dim.h < grid_size)
	{
		dim.w = 0;
		while (dim.w < grid_size)
		{
			if (thread_id >= sys_data()->cpu_cores)
				break ;
			config_thread(&dim, &thread_id, tile, threads);
			dim.w++;
		}
		dim.h++;
	}
	i = 0;
	while (i < thread_id)
	{
		pthread_join(threads[i].pid, NULL);
		i++;
	}
}

void	render_scene(void)
{
	t_thread	*threads;
	int			grid_size;
	int			tile[2];
	int			thread_id;

	threads = new_(sizeof(t_thread) * sys_data()->cpu_cores);
	grid_size = sqrt(sys_data()->cpu_cores);
	tile[0] = sys_data()->screen_width / grid_size;
	tile[1] = sys_data()->screen_height / grid_size;
	thread_id = 0;
	pthread_mutex_init(&sys_data()->pixel_lock, NULL);
	launch_and_join(threads, thread_id, grid_size, tile);
	delete_(threads);
}
