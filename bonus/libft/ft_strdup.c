/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:16:16 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/02 13:16:18 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	const char	*clone;
	int			len;

	len = ft_strlen(s1);
	clone = new_(sizeof(char) * (len + 1));
	if (!clone)
		return (NULL);
	ft_memcpy((void *)clone, s1, len + 1);
	return ((char *)clone);
}

// #include <stdio.h>
// #include <string.h>
// int main(){
// 	// printf("mine: %s\n", ft_strdup(NULL));
// 	printf("theirs: %s\n", strdup(NULL));
// }
