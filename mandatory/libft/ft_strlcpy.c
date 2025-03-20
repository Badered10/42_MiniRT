/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:19:34 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/17 17:43:59 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest,
		const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (src_len < dstsize)
		ft_strncpy(dest, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_strncpy(dest, src, dstsize - 1);
		dest[dstsize - 1] = '\0';
	}
	return (src_len);
}
