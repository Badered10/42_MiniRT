/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:08:46 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/17 19:54:19 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	translation(int keycode)
{
	t_vec3	vec;

	if (keycode == DWON_Y)
		vec = (t_vec3){0, -0.5, 0};
	else if (keycode == UP_Y)
		vec = (t_vec3){0, 0.5, 0};
	else if (keycode == BACK_Z)
		vec = (t_vec3){0, 0, -0.5};
	else if (keycode == FORWORD_Z)
		vec = (t_vec3){0, 0, 0.5};
	else if (keycode == RIGHT_X)
		vec = (t_vec3){-0.5, 0, 0};
	else if (keycode == LEFT_X)
		vec = (t_vec3){0.5, 0, 0};
	else
		return (-1);
	translate_shape(scene()->obj_to_move, vec);
	return (0);
}

int	rotation(int keycode)
{
	if (keycode == I)
		rotate_shape(scene()->obj_to_move->shape, ROT_SPEED,
			scene()->obj_to_move->type, X_AXIS);
	else if (keycode == K)
		rotate_shape(scene()->obj_to_move->shape, -ROT_SPEED,
			scene()->obj_to_move->type, X_AXIS);
	else if (keycode == J)
		rotate_shape(scene()->obj_to_move->shape, -ROT_SPEED,
			scene()->obj_to_move->type, Y_AXIS);
	else if (keycode == L)
		rotate_shape(scene()->obj_to_move->shape, ROT_SPEED,
			scene()->obj_to_move->type, Y_AXIS);
	else if (keycode == U)
		rotate_shape(scene()->obj_to_move->shape, ROT_SPEED,
			scene()->obj_to_move->type, Z_AXIS);
	else if (keycode == O)
		rotate_shape(scene()->obj_to_move->shape, -ROT_SPEED,
			scene()->obj_to_move->type, Z_AXIS);
	else
		return (-1);
	return (0);
}

int	scaling(int keycode)
{
	static bool	mode;

	if (keycode == ALT)
		mode = !mode;
	else if (keycode == PLUS)
		scale_diameter(scene()->obj_to_move, MUL_SCALE, mode);
	else if (keycode == MIN)
		scale_diameter(scene()->obj_to_move, DIV_SCALE, mode);
	else
		return (-1);
	return (0);
}

void	move_any(int keycode, bool *render)
{
	*render = (keycode == PLUS || keycode == MIN || keycode == DWON_Y
			|| keycode == UP_Y || keycode == BACK_Z || keycode == FORWORD_Z
			|| keycode == RIGHT_X || keycode == LEFT_X || keycode == K
			|| keycode == I || keycode == J || keycode == L || keycode == U
			|| keycode == O);
	if (!translation(keycode))
		return ;
	if (!rotation(keycode))
		return ;
	if (!scaling(keycode))
		return ;
}
