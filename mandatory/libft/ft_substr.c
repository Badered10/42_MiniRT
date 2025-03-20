/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:26:29 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/02 13:26:30 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len || *s == '\0')
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	substring = new_(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	ft_memcpy(substring, s + start, len);
	substring[len] = '\0';
	return (substring);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char *ptr = "hello there!";
// 	printf("%s\n", ft_substr(NULL, 4, 0));
// }