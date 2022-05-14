/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:45:57 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/12 21:42:52 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_pixel p1, t_pixel p2, t_data *data)
{
	t_draw	*c_data;
	double	t;

	c_data = init_draw(&p1, &p2);
	t = (double)max(p1.old_z, p2.old_z) / 10.;
	while (c_data->current.x != p2.x || c_data->current.y != p2.y)
	{
		map_pixel_put(data, c_data->current.x, \
						c_data->current.y, bernstein(t));
		c_data->decision[1] = c_data->decision[0] * 2;
		if (c_data->decision[1] > -c_data->delta.y)
		{
			c_data->decision[0] -= c_data->delta.y;
			c_data->current.x += c_data->sign.x;
		}
		if (c_data->decision[1] < c_data->delta.x)
		{
			c_data->decision[0] += c_data->delta.x;
			c_data->current.y += c_data->sign.y;
		}
	}
	free(c_data);
}

static void	background_coloring(t_data *data)
{
	int	i;
	int	*img_ptr;

	img_ptr = (int *)data->data_addr;
	i = 0;
	while (i <= HEIGHT * WIDTH)
	{
		img_ptr[i] = 0x00ffffff;
		i++;
	}
}

static void	print_menu(t_data *data)
{
	int	i;
	int	j;
	int	starting_point;
	int	*img_ptr;

	i = 0;
	img_ptr = (int *)data->data_addr;
	starting_point = WIDTH - M_WIDTH;
	while (i < M_HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (j >= starting_point)
				info_pixel_put(data, j, i, 0x00ffeda6);
			j++;
		}
		i++;
	}
}

void	draw(t_pixel **lines_map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	background_coloring(data);
	print_menu(data);
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
	put_strings_to_image(data);
}
