/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:19:17 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/02 13:19:19 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	src_index = 0;
	while (src[src_index] && (dst_len + 1) < size)
	{
		dst[dst_len] = src[src_index];
		src_index++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (dst_len + ft_strlen(&src[src_index]));
}

// #include <stdio.h>πsplit

// int main() {
//     char dst[100] = "Hello there how are you......!";
//     char src[100] = "how are";
//     size_t size = 150;

//     dst[0] = '\0';

//     ft_strlcat(dst, src, 100);

//     printf("%s\n", dst);

//     return 0;
// }