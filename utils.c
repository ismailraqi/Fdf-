/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:47:05 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/17 19:05:11 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	sign_test(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

int	get_hight(t_pixel *pixel, char *str)
{
	int		i;
	int		t;

	if (!str)
		return (-1);
	i = 0;
	t = -1 * (str[i] == '-') + (str[i] == '+');
	i += (t != 0);
	t += (t == 0);
	while (str[i] >= '0' && str[i] <= '9')
		pixel->z = (i++, 10 * pixel->z + (str[i - 1] - '0'));
	pixel->z *= t;
	return (0);
}

void	put_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 2);
}
