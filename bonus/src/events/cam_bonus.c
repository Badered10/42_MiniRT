/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:07:27 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/19 08:22:41 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	cam_rotations(int keycode, t_camera *cam)
{
	if (keycode == I)
		cam->pos = rotate_x(cam->pos, -ROT_SPEED);
	else if (keycode == K)
		cam->pos = rotate_x(cam->pos, ROT_SPEED);
	else if (keycode == L)
		cam->pos = rotate_y(cam->pos, -ROT_SPEED);
	else if (keycode == J)
		cam->pos = rotate_y(cam->pos, ROT_SPEED);
	else if (keycode == U)
		cam->pos = rotate_z(cam->pos, -ROT_SPEED);
	else if (keycode == O)
		cam->pos = rotate_z(cam->pos, ROT_SPEED);
	else
		return (-1);
	return (0);
}

int	cam_movements(int keycode, t_camera *cam, t_vec3 forward)
{
	t_vec3	delta;
	t_vec3	right;

	if (keycode == W)
		delta = mult_(forward, MOVE_SPEED);
	else if (keycode == S)
		delta = mult_(forward, -MOVE_SPEED);
	else if (keycode == A)
	{
		right = cross_(forward, (t_vec3){0, 1, 0});
		norm_(&right);
		delta = mult_(right, -MOVE_SPEED);
	}
	else if (keycode == D)
	{
		right = cross_(forward, (t_vec3){0, 1, 0});
		norm_(&right);
		delta = mult_(right, MOVE_SPEED);
	}
	else
		return (-1);
	cam->pos = sum_(cam->pos, delta);
	cam->direction = sum_(cam->direction, delta);
	return (0);
}

void	camera_hundler(int keycode, bool *render)
{
	t_camera	*cam;
	t_vec3		forward;

	cam = scene()->camera;
	forward = sub_(cam->direction, cam->pos);
	*render = (keycode == W || keycode == S || keycode == A || keycode == D
			|| keycode == K || keycode == I || keycode == L || keycode == J
			|| keycode == U || keycode == O);
	if (!cam_movements(keycode, cam, forward))
		return ;
	else
		cam_rotations(keycode, cam);
}
