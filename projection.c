/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:44:22 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/22 04:49:18 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * 0.86602540378;
	*y = (previous_x + previous_y) * 0.5 - z;
}

static	void	zoom_apply(t_pixel *pixel, t_data *data)
{
	pixel->x *= data->cam->zoom;
	pixel->y *= data->cam->zoom;
}

static	t_pixel	projection_n_shift(t_pixel pixel, t_data *data)
{
	int	a;
	int	b;

	pixel.old_z = pixel.z;
	a = (data->map->width / 2) * data->cam->zoom;
	b = (data->map->height / 2) * data->cam->zoom;
	if (data->is_parallel == 1)
	{
		iso(&pixel.x, &pixel.y, pixel.z);
		iso(&a, &b, 0);
		x_rotation(data->cam->x_angle, &pixel.y, pixel.z);
		y_rotation(data->cam->y_angle, &pixel.x, &pixel.z, pixel.y);
		z_rotation(data->cam->z_angle, &pixel.y, pixel.z, &pixel.x);
	}
	pixel.x += data->cam->x_pos - a;
	pixel.y += data->cam->y_pos - b;
	return (pixel);
}

t_pixel	wrapper(t_pixel p, t_data *data)
{
	t_pixel	new_p;

	new_p = p;
	zoom_apply(&new_p, data);
	new_p = projection_n_shift(new_p, data);
	return (new_p);
}
