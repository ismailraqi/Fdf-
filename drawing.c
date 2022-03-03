#include "fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    if ((x < WIDTH && x > 0) && (y < HEIGHT && y > 0))
    {
        dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}


static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * 0.86602540378;
    *y = (previous_x + previous_y) * 0.5 - z;
}

t_pixel wrapper(t_pixel p)
{
    iso(&p.x, &p.y, p.z);
    return (p);
}

static int sign_test(int a, int b)
{
    if (a < b)
        return (1);
    return (-1);
}

t_draw *init_draw(t_pixel p1, t_pixel p2)
{
    t_draw *data;

    data = (t_draw *)malloc(sizeof(t_draw));
    if (!data)
        return (NULL);
    data->delta.x = abs(p2.x - p1.x);
    data->delta.y = abs(p2.y - p1.y);
    data->sign.x = sign_test(p1.x, p2.x);
    data->sign.y = sign_test(p1.y, p2.y);
    data->current = p1;
    data->error[0] = data->delta.x - data->delta.y;
    return (data);
}

void	draw_line(t_pixel p1, t_pixel p2, t_data *data)
{
    t_draw *c_data;

    int c;
    c_data = init_draw(p1, p2);
    if (p1.z != 0 || p2.z != 0)
        c = 0x00604511;
    else 
        c = 0x009045ff;
	while (c_data->current.x != p2.x || c_data->current.y != p2.y)
	{
		my_mlx_pixel_put(data, c_data->current.x, c_data->current.y, c);
		if ((c_data->error[1] = c_data->error[0] * 2) > -c_data->delta.y)
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

void draw(t_pixel **lines_map, t_data *data)
{
    int y;
    int x;

    y = 0;
    while (y <= data->map->height - 1)
    {
        x = 0;
        while (x <= data->map->width - 1)
        {
            if (x != data->map->width - 1)
                draw_line(lines_map[y][x], lines_map[y][x + 1], data);
            if (y != data->map->height - 1)
                draw_line(lines_map[y][x], lines_map[y + 1][x], data);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
