/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:03:30 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/19 08:24:39 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	split_len(char **split)
{
	int	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	not_digits_check(char *arg, int line)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '.' && arg[i] != '-'
			&& arg[i] != '+')
			throw_error("There is a non digit char: ", line, arg);
		else if ((arg[i] == '.' && !ft_isdigit(arg[i + 1])) || (arg[i] == '-'
				&& !ft_isdigit(arg[i + 1])) || (arg[i] == '+'
				&& !ft_isdigit(arg[i + 1])))
			throw_error("Special character follwed by non digit : ", line, arg);
	}
	if (!ft_isdigit(arg[i - 1]))
		throw_error("Number must not end with non digit: ", line, arg);
}

void	check_multi(char *arg, int line)
{
	char	*first;
	char	*last;

	first = ft_strchr(arg, '.');
	last = ft_strrchr(arg, '.');
	if ((first != last) && (first && last))
		throw_error("There is multiple points: ", line, arg);
	first = ft_strchr(arg, '-');
	last = ft_strrchr(arg, '-');
	if ((first != last) && (first && last))
		throw_error("There is multiple minces: ", line, arg);
	first = ft_strchr(arg, '+');
	last = ft_strrchr(arg, '+');
	if ((first != last) && (first && last))
		throw_error("There is multiple pluses: ", line, arg);
}

double	non_double(double min, double max, char *arg, int line)
{
	double	res;

	res = (double)ft_atoi(arg);
	if (res < min || res > max)
		throw_error("Value out of range in line: ", line, arg);
	return (res);
}

double	double_guard(char *arg, int line, double min, double max)
{
	double	left;
	double	right;
	char	**lighting_ratio;
	double	res;
	bool	single_dot;

	check_multi(arg, line);
	not_digits_check(arg, line);
	lighting_ratio = ft_split(arg, ".");
	if (!ft_strchr(arg, '.'))
		return (non_double(min, max, arg, line));
	single_dot = (split_len(lighting_ratio) == 1);
	left = 0.0;
	if (!single_dot)
		left = ft_atoi(lighting_ratio[0]);
	right = ft_atoi(lighting_ratio[!single_dot]);
	if ((left > max) || (left == max && right != 0))
		throw_error("Value out of range in line: ", line, arg);
	res = left;
	res += -(left < 0) * (double)((right) * pow(10, -(ft_intlen(right))));
	res += (left >= 0) * (double)((right) * pow(10, -(ft_intlen(right))));
	if (res < min)
		throw_error("Value out of range in line: ", line, arg);
	return (res);
}
