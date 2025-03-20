/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:16:10 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:19 by baouragh         ###   ########.fr       */
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

void	compute_ray(t_vec3 pixel_center, t_render_range *rr_, int x, int y)
{
	t_vec3	rgb;
	int		s;
	int		samples;
	t_color	simple_color;

	if (scene()->aa_round > 0)
		samples = scene()->aa_round;
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
	put_pixel(x, y, to_hex(rgb.x, rgb.y, rgb.z));
}

void	render_state(t_render_range *rr_, int x, int y)
{
	t_vec3	pixel_center;

	pixel_center = sum_(rr_->viewport_upper_left, sum_(mult_(rr_->h_pixel_delta,
					x), mult_(rr_->v_pixel_delta, y)));
	compute_ray(pixel_center, rr_, x, y);
}

void	render(void)
{
	t_render_range	*rr_;
	int				x;
	int				y;

	rr_ = new_(sizeof(t_render_range));
	calc_scene(rr_);
	y = 0;
	while (y < scene()->screen_height)
	{
		x = 0;
		while (x < scene()->screen_width)
		{
			render_state(rr_, x, y);
			x++;
		}
		y++;
	}
}
