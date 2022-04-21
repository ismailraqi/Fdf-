/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 06:23:46 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/21 06:41:03 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotation(float angle, int *y, int z)
{
	*y = *y * cos(angle) - z * sin(angle);
	z = z * sin(angle) + z * cos(angle);
}

void	y_rotation(float angle, int *x, int *z, int y)
{
	*x = *z * sin(angle) + *x * cos(angle);
	*z = y * cos(angle) - *x * sin(angle);
}

void	z_rotation(float angle, int *y, int z, int *x)
{
	*x = *x * cos(angle) - *y * sin(angle);
	*y = *x * sin(angle) + *y * cos(angle);
}
