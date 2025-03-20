/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:20:15 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 05:32:35 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error_hlper(char *msg, int line, size_t *size, char *add)
{
	if (add)
	{
		ft_putstr_fd("|", STDERR_FILENO);
		ft_putstr_fd(add, STDERR_FILENO);
		*size = ft_strlen(add);
		while ((*size++) < (ft_strlen(msg) + ft_strlen(ft_itoa(line))))
			ft_putstr_fd(" ", STDERR_FILENO);
		ft_putstr_fd("|\n", STDERR_FILENO);
	}
	ft_putstr_fd("|", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (line != -1)
		ft_putnbr_fd(line, STDERR_FILENO);
}

void	throw_error(char *msg, int line, char *add)
{
	size_t	size;

	ft_putstr_fd(RED "Error\n" RESET, STDERR_FILENO);
	size = ft_strlen(msg);
	if (line != -1)
		size += ft_strlen(ft_itoa(line));
	ft_putstr_fd("+", STDERR_FILENO);
	while (size--)
		ft_putstr_fd("-", STDERR_FILENO);
	ft_putstr_fd("+\n", STDERR_FILENO);
	error_hlper(msg, line, &size, add);
	ft_putstr_fd("|\n", STDERR_FILENO);
	size = ft_strlen(msg) + ft_strlen(ft_itoa(line));
	ft_putstr_fd("+", STDERR_FILENO);
	while (size--)
		ft_putstr_fd("-", STDERR_FILENO);
	ft_putstr_fd("+\n", STDERR_FILENO);
	safe_close(0);
	exit(1);
}
