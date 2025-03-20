/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:19:17 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:52:53 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	insert_cone(t_cone *cone)
{
	t_cone	*cone_node;

	cone_node = scene()->cone_list;
	if (!cone_node)
	{
		scene()->cone_list = cone;
		return ;
	}
	while (cone_node->next)
		cone_node = cone_node->next;
	cone_node->next = cone;
}
