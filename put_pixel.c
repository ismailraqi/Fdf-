/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:40:47 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/22 02:56:39 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < (WIDTH - M_WIDTH) && x >= 0) && (y < HEIGHT && y >= 0))
	{
		dst = data->data_addr + (y * data->size_line + x \
								* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	info_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < WIDTH && x >= 0) && (y < HEIGHT && y >= 0))
	{
		dst = data->data_addr + (y * data->size_line + x \
								* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
