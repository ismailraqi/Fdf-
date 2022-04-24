/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_into_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:01:00 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/24 04:53:31 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_strings_to_image(t_data *data)
{
	int	start;

	start = WIDTH - M_WIDTH;
	mlx_string_put(data->mlx, data->win, start, 5, \
	0x00000000, "=> USE ( X / Z / Y )");
	mlx_string_put(data->mlx, data->win, start, 20, \
	0x008c8a82, "TO ROTATE THE SHAPE ( CLOCKWISE )");
	mlx_string_put(data->mlx, data->win, start, 50, \
	0x00000000, "=> USE ( S / A / D )");
	mlx_string_put(data->mlx, data->win, start, 65, \
	0x008c8a82, "TO ROTATE THE SHAPE ( ANTICLOCKWISE )");
	mlx_string_put(data->mlx, data->win, start, 95, \
	0x00000000, "=> USE ( UP / DOWN / LEFT / RIGHT )");
	mlx_string_put(data->mlx, data->win, start, 110, \
	0x008c8a82, "TO MOVE THE SHAPE");
	mlx_string_put(data->mlx, data->win, start, 140, \
	0x00000000, "=> USE MOUSE SCROLL WHEEL ( UP / DOWN)");
	mlx_string_put(data->mlx, data->win, start, 155, \
	0x008c8a82, "ZOOM IN AND OUT");
	mlx_string_put(data->mlx, data->win, start, 185, \
	0x00000000, "=> USE ( P / I ) TO SWITCH PROJECTION");
	mlx_string_put(data->mlx, data->win, start, 200, \
	0x008c8a82, "P ( PARALLEL ) | I ( ISO )");
}
