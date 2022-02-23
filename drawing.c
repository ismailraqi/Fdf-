#include "fdf.h"

int Sign(int dxy)
{
    if (dxy < 0)
        return (-1);
    else if (dxy > 0)
        return (1);
    else
        return (0);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    if ((x < WIDTH && x > 0) && (y < HEIGHT && y > 0))
    {
        dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

t_draw *init_draw(t_pixel p1, t_pixel p2)
{
    t_draw *data;

    data = (t_draw *)malloc(sizeof(t_draw));
    if (!data)
        return (NULL);
    data->delta.x = p2.x - p1.x;
    data->delta.y = p2.y - p1.y;
    data->sign.x = Sign(data->delta.x);
    data->sign.y = Sign(data->delta.y);
    data->current.x = p1.x;
    data->current.y = p1.y;
    data->d = MAX(data->delta.x, data->delta.y);
    data->r = data->d / 2;
    return (data);
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

// void draw_line(t_pixel p_1, t_pixel p_2, t_data *data)
// {
//     p_1.x *= 20;
//     p_1.y *= 20;
//     // p_1.z *= 20;
//     p_2.x *= 20;
//     p_2.y *= 20;
//     // p_2.z *= 10;
//     t_draw *c_data;
//     int i;
//     iso(&p_1.x, &p_1.y, p_1.z);
//     iso(&p_2.x, &p_2.y, p_2.z);
//     p_1.x += 200;
//     p_1.y += 200;
//     p_2.x += 200;
//     p_2.y += 200;
//     c_data = init_draw(p_1, p_2);
//     i = -1;
//     int c;
//     if (p_1.z != 0 || p_2.z != 0)
//         c = 0x00254511;
//     else 
//         c = 0x002545ff;
//     if (c_data->delta.x > c_data->delta.y)
//     {
//         while (++i < c_data->d)
//         {
//             my_mlx_pixel_put(data, c_data->current.x, c_data->current.y, c);
//             (c_data->current.x += c_data->sign.x, c_data->r += c_data->delta.y);
//             if (c_data->r >= c_data->delta.x)
//                 (c_data->current.y += c_data->sign.y, c_data->r -= c_data->delta.x);
//         }
//     }
//     else
//     {
//         while (++i < c_data->d)
//         {
//             my_mlx_pixel_put(data, c_data->current.x, c_data->current.y, c);
//             (c_data->current.y += c_data->sign.y, c_data->r += c_data->delta.x);
//             if (c_data->r >= c_data->delta.y)
//                 (c_data->current.x += c_data->sign.x, c_data->r -= c_data->delta.y);
//         }
//     }
// }


// void    draw_2(t_pixel p1, t_pixel p2, t_data *data)
// {
//     p1.x *= 20;
//     p1.y *= 20;
//     // p1.z *= 20;
//     p2.x *= 20;
//     p2.y *= 20;
//     int dx = abs(p2.x - p1.x);
//     int sx = p1.x < p2.x ? 1 : - 1;
//     int dy = -abs(p2.y - p1.y);
//     int sy = p1.y < p2.y ? 1 : - 1;
//     int er = dx -dy;
//     int e2;
//     t_pixel current;
//     current.x = p1.x;
//     current.y = p1.y;
//     while (1)
//     {
//         my_mlx_pixel_put(data, current.x, current.y, 0xEC4521);
//         if (current.x == p2.x && current.y == p2.y)
//             break;
//         e2 = 2 * er;
//         if (e2 >= dy)
//         {
//             if (current.x == p2.x)
//                 break;
//             er += dy;
//             current.x += sx;
//         }
//         if (e2 <= dx)
//         {
//             if (current.y == p2.y)
//                 break;
//             er += dx;
//             current.y += sy;
//         }
//     }
// }

void	draw_line(t_pixel f, t_pixel s, t_data *fdf)
{
	t_pixel	delta;
	t_pixel	sign;
	t_pixel	cur;
	int		error[2];
    f.x *= 30;
    f.y *= 30;
    // p_1.z *= 30;
    s.x *= 30;
    s.y *= 30;
    iso(&f.x, &f.y, f.z);
    iso(&s.x, &s.y, s.z);
    f.x += 150;
    f.y += 150;
    s.x += 150;
    s.y += 150;
	delta.x = abs(s.x - f.x);
	delta.y = abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
    int c;

    if (f.z != 0 || s.z != 0)
        c = 0x00604511;
    else 
        c = 0x009045ff;
	while (cur.x != s.x || cur.y != s.y)
	{
		my_mlx_pixel_put(fdf, cur.x, cur.y, c);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
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
