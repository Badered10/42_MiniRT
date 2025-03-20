/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:03:23 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 23:33:37 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**
 * sp 0.0,0.0,20.6 12.6 10,0,255
 * identifier: sp
 * position of center: 0.0,0.0,20.6
 * diameter: 12.6
 * color: 10,0,255
 */
void	destroy_textures(void)
{
	t_texture_req	*curr;

	curr = scene()->texture_req_list;
	while (curr)
	{
		if (curr->sphere->texture->data.img)
			mlx_destroy_image(*mlx(), curr->sphere->texture->data.img);
		curr = curr->next;
	}
}

void	request_texture(t_sphere *res)
{
	t_texture_req	*req;
	t_texture_req	*tmp;

	req = new_(sizeof(t_texture_req));
	if (!req)
		throw_error("Failed to allocate memory", -1, NULL);
	req->sphere = res;
	req->next = NULL;
	tmp = scene()->texture_req_list;
	if (!tmp)
	{
		scene()->texture_req_list = req;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = req;
}

t_sphere	*sphere_guard(char **split, int line_count)
{
	t_sphere	*res;

	if (split_len(split) < 4 || split_len(split) > 5)
		throw_error("Invalid sphere arguments at line: ", line_count, NULL);
	res = new_(sizeof(t_sphere));
	res->pos = point_guard(split[1], line_count, DOUBLE_MIN, DOUBLE_MAX);
	res->diameter = double_guard(split[2], line_count, 0.1, DOUBLE_MAX);
	res->color = color_guard(split[3], line_count);
	res->next = NULL;
	res->type = SPHERE;
	res->texture = NULL;
	if (split_len(split) == 5)
	{
		res->texture = new_(sizeof(t_image));
		res->texture->file_name = split[4];
		request_texture(res);
	}
	insert_sphere(res);
	return (res);
}

void	apply_textures(void)
{
	t_sphere		*sp;
	t_texture_req	*tmp;

	tmp = scene()->texture_req_list;
	while (tmp)
	{
		sp = tmp->sphere;
		sp->texture->data.img = mlx_xpm_file_to_image(*mlx(),
				sp->texture->file_name, &(sp->texture->size.w),
				&(sp->texture->size.h));
		if (!(sp->texture->data.img))
			throw_error("Failed to load texture", -1, sp->texture->file_name);
		sp->texture->data.addr = mlx_get_data_addr(sp->texture->data.img,
				&sp->texture->data.bits_per_pixel,
				&sp->texture->data.line_length,
				&sp->texture->data.endian);
		tmp = tmp->next;
	}
}

int	texture_pixel(t_image *texture, int x, int y)
{
	char	*dst;

	dst = texture->data.addr + (y * texture->data.line_length + x
			* (texture->data.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
