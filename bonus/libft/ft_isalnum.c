/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:33 by abchikhi          #+#    #+#             */
/*   Updated: 2023/10/30 18:24:56 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
int main(){
	char c = '4';
	char f_c = 'r';
	printf("c: %d\n", ft_isalnum(c));
	printf("f_c: %d\n", ft_isalnum(f_c));
	printf("c2: %d\n", ft_isalnum('*'));
	return 0;
	return 0;
}
*/
