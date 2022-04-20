/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:45:57 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/20 00:02:58 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_pixel p1, t_pixel p2, t_data *data)
{
	t_draw	*c_data;
	double	t;

	c_data = init_draw(&p1, &p2, data);
	t = (double)max(p1.z, p2.z) / 10.;
	while (c_data->current.x != p2.x || c_data->current.y != p2.y)
	{
		my_mlx_pixel_put(data, c_data->current.x, \
		c_data->current.y, bernstein(t));
		c_data->error[1] = c_data->error[0] * 2;
		if (c_data->error[1] > -c_data->delta.y)
		{
			c_data->error[0] -= c_data->delta.y;
			c_data->current.x += c_data->sign.x;
		}
		if (c_data->error[1] < c_data->delta.x)
		{
			c_data->error[0] += c_data->delta.x;
			c_data->current.y += c_data->sign.y;
		}
	}
}

static void	background_coloring(t_data *data)
{
	int	i;
	int	j;
	int	*img_ptr;

	img_ptr = (int *)data->data_addr;
	i = 0;
	while (i <= HEIGHT * WIDTH)
	{
		img_ptr[i] = 0x00ffffff;
		i++;
	}
}

void	draw(t_pixel **lines_map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	background_coloring(data);
	while (y <= data->map->height - 1)
	{
		x = 0;
		while (x <= data->map->width - 1)
		{
			if (x != data->map->width - 1)
				draw_line(wrapper(lines_map[y][x], data), \
				wrapper(lines_map[y][x + 1], data), data);
			if (y != data->map->height - 1)
				draw_line(wrapper(lines_map[y][x], data), \
				wrapper(lines_map[y + 1][x], data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
