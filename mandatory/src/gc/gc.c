/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 04:59:33 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 03:54:50 by baouragh         ###   ########.fr       */
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
	if (!*local_gc())
	{
		gc->next = NULL;
		*local_gc() = gc;
	}
	else
	{
		gc->next = *local_gc();
		*local_gc() = gc;
	}
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
			if (prev)
				prev->next = iter->next;
			else
				*local_gc() = iter->next;
			free(iter->ptr);
			free(iter);
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

	iter = *local_gc();
	while (iter)
	{
		next = iter->next;
		free(iter->ptr);
		free(iter);
		iter = next;
	}
	*local_gc() = NULL;
}
