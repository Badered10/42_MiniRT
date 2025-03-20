/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:16:10 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 02:04:56 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	check_range(t_vec3 rgb, int samples)
{
	rgb.x /= samples;
	rgb.y /= samples;
	rgb.z /= samples;
	if (rgb.x > 255)
		rgb.x = 255;
	if (rgb.y > 255)
		rgb.y = 255;
	if (rgb.z > 255)
		rgb.z = 255;
	return (rgb);
}

void	pixel_destination(t_vec3 rgb, int x, int y)
{
	pthread_mutex_lock(&sys_data()->pixel_lock);
	if (sys_data()->full_render)
		mlx_pixel_put(*mlx(), *mlx_win(), x, y, to_hex(rgb.x, rgb.y, rgb.z));
	else
		put_pixel(x, y, to_hex(rgb.x, rgb.y, rgb.z));
	pthread_mutex_unlock(&sys_data()->pixel_lock);
}

void	compute_ray(t_vec3 pixel_center, t_render_range *rr_, int x, int y)
{
	t_vec3	rgb;
	int		s;
	int		samples;
	t_color	simple_color;

	if (!sys_data()->full_render)
		samples = 1;
	else if (sys_data()->aa_round > 0)
		samples = sys_data()->aa_round;
	else
		samples = 1;
	rgb = (t_vec3){0, 0, 0};
	s = -1;
	while (++s < samples)
	{
		simple_color = compute_pixel_color(pixel_center, rr_);
		rgb.x += simple_color.r;
		rgb.y += simple_color.g;
		rgb.z += simple_color.b;
	}
	rgb = check_range(rgb, samples);
	pixel_destination(rgb, x, y);
}

void	render_state(t_render_range *rr_, int x, int y)
{
	t_vec3	pixel_center;

	if ((x % 2 && y % 2) || sys_data()->full_render)
	{
		pixel_center = sum_(rr_->viewport_upper_left,
				sum_(mult_(rr_->h_pixel_delta, x), mult_(rr_->v_pixel_delta,
						y)));
		compute_ray(pixel_center, rr_, x, y);
	}
	else
	{
		pthread_mutex_lock(&sys_data()->pixel_lock);
		put_pixel(x, y, 0);
		pthread_mutex_unlock(&sys_data()->pixel_lock);
	}
}

void	*render(void *rr)
{
	t_render_range	*rr_;
	int				x;
	int				y;

	rr_ = rr;
	y = rr_->y_range[1];
	while (y > rr_->y_range[0])
	{
		x = rr_->x_range[0];
		while (x < rr_->x_range[1])
		{
			render_state(rr_, x, y);
			x++;
		}
		y--;
	}
	return (NULL);
}
