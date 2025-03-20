/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:21:57 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/02 13:21:59 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		front;
	int		rear;
	int		len;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	while (s1[front] && is_set(s1[front], set))
		front++;
	rear = ft_strlen(s1) - 1;
	while (rear > front && is_set(s1[rear], set))
		rear--;
	len = rear - front + 1;
	if (len <= 0)
		return (ft_strdup(""));
	res = new_(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1 + front, len + 1);
	return (res);
}
