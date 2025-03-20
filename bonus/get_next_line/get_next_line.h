/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:35:19 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/30 18:07:08 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/select.h>
# include "../includes/gc.h"

# ifdef BUFFER_SIZE
#  undef BUFFER_SIZE
# endif

# define BUFFER_SIZE 128

typedef struct s_store
{
	int		bytes;
	int		signal;
	char	*buff;
	char	*temp;
	char	*new_line_pos;
	char	*line;
}	t_store;

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);

#endif
