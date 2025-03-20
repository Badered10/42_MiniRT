/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:39:26 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/02 17:39:27 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	unsigned_c;
	size_t			i;

	str = (unsigned char *)s;
	unsigned_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == unsigned_c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
