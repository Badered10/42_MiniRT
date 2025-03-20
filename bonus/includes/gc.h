/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:34:15 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 06:19:15 by abchikhi         ###   ########.fr       */
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
