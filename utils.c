/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:47:05 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/21 07:05:43 by iraqi            ###   ########.fr       */
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

static	int	contains(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
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
