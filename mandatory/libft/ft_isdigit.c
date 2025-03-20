/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:34:45 by abchikhi          #+#    #+#             */
/*   Updated: 2023/10/30 18:25:55 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c <= '9' && c >= '0');
}

/*
int main(){
	char c = '4';
	char f_c = 'r';
	printf("c: %d\n", ft_isdigit(c));
	printf("f_c: %d\n", ft_isdigit(f_c));
	return 0;
}
*/
