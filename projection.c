/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:44:22 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/19 23:55:05 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static  void    iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * 0.86602540378;
    *y = (previous_x + previous_y) * 0.5 - z;
}

static  void    zoom_apply(t_pixel *pixel, t_data *data)
{
    pixel->x *= data->cam->zoom;
    pixel->y *= data->cam->zoom;
}
 
static  t_pixel projection_n_shift(t_pixel pixel, t_data *data)
{
    int     a;
    int     b;

    a = (data->map->width / 2) * data->cam->zoom;
    b = (data->map->height / 2) * data->cam->zoom;
    if (data->is_parallel == 1)
    {
        iso(&pixel.x, &pixel.y, pixel.z);
        iso(&a, &b, 0);
    }
    pixel.x += data->cam->x_pos - a;
    pixel.y += data->cam->y_pos - b;
    return (pixel);
}

t_pixel wrapper(t_pixel p, t_data *data)
{
    t_pixel     new_p;

    new_p = p;
    zoom_apply(&new_p, data);
    new_p = projection_n_shift(new_p, data);
    return (new_p);
}