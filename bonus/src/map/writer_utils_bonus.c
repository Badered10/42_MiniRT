/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:19:17 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 06:07:14 by abchikhi         ###   ########.fr       */
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
