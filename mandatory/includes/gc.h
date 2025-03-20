/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:48:11 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/17 19:49:07 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include "libs.h"

typedef struct gc_s
{
	void	*ptr;
	void	*next;
}			t_gc;

void		*new_(size_t size);
void		delete_(void *gc);
void		clean_(void);

#endif