/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:23:55 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/25 22:51:35 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_initializer(t_pixel *last)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		exit(EXIT_FAILURE);
	map->map_size = last->count;
	map->height = last->y + 1;
	map->width = ((last->count + 1) / (last->y + 1));
	return (map);
}

t_data	*mlx_initializer(void)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
										&data->size_line, &data->endian);
	data->is_parallel = 0;
	return (data);
}

t_cam	*cam_initializer(t_data *data)
{
	t_cam	*cam;

	cam = (t_cam *) malloc(sizeof(t_cam));
	cam->x_pos = ((WIDTH - M_WIDTH) / 2);
	cam->y_pos = (HEIGHT / 2);
	if (((WIDTH - M_WIDTH) / data->map->width / 2) \
					> (HEIGHT / data->map->height / 2))
		cam->zoom = (HEIGHT / data->map->height / 2);
	else
		cam->zoom = ((WIDTH - M_WIDTH) / data->map->width / 2);
	if (cam->zoom <= 0)
		cam->zoom = 0.5;
	cam->x_angle = 0.;
	cam->y_angle = 0.;
	cam->z_angle = 0.;
	return (cam);
}

t_draw	*init_draw(t_pixel *p1, t_pixel *p2)
{
	t_draw	*data;

	data = (t_draw *)malloc(sizeof(t_draw));
	if (!data)
		return (NULL);
	data->delta.x = abs(p2->x - p1->x);
	data->delta.y = abs(p2->y - p1->y);
	data->sign.x = sign_test(p1->x, p2->x);
	data->sign.y = sign_test(p1->y, p2->y);
	data->current = *p1;
	data->decision[0] = (data->delta.x - data->delta.y);
	return (data);
}
