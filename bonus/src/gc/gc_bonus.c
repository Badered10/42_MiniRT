/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:59:33 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:55:10 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_gc	**local_gc(void)
{
	static t_gc	*gc = NULL;

	return (&gc);
}

void	*new_(size_t size)
{
	t_gc	*gc;

	gc = malloc(sizeof(t_gc));
	if (!gc)
		throw_error("malloc failed", -1, NULL);
	gc->ptr = malloc(size);
	if (!gc->ptr)
	{
		free(gc);
		throw_error("malloc failed", -1, NULL);
	}
	ft_bzero(gc->ptr, size);
	pthread_mutex_lock(&sys_data()->gc_lock);
	if (!*local_gc())
		gc->next = NULL;
	else
		gc->next = *local_gc();
	*local_gc() = gc;
	pthread_mutex_unlock(&sys_data()->gc_lock);
	return (gc->ptr);
}

void	delete_(void *ptr)
{
	t_gc	*iter;
	t_gc	*prev;

	iter = *local_gc();
	prev = NULL;
	while (iter)
	{
		if (iter->ptr == ptr)
		{
			pthread_mutex_lock(&sys_data()->gc_lock);
			if (prev)
				prev->next = iter->next;
			else
				*local_gc() = iter->next;
			free(iter->ptr);
			free(iter);
			pthread_mutex_unlock(&sys_data()->gc_lock);
			break ;
		}
		prev = iter;
		iter = iter->next;
	}
}

void	clean_(void)
{
	t_gc	*iter;
	t_gc	*next;

	pthread_mutex_lock(&sys_data()->gc_lock);
	destroy_textures();
	iter = *local_gc();
	while (iter)
	{
		next = iter->next;
		free(iter->ptr);
		free(iter);
		iter = next;
	}
	*local_gc() = NULL;
	pthread_mutex_unlock(&sys_data()->gc_lock);
}
