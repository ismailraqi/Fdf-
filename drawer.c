# include "fdf.h"

int Sign(int dxy)
{
    if (dxy<0) 
        return (-1); 
    else if (dxy>0) 
        return (1); 
    else 
        return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
    if (x < WIDTH && y < HEIGHT)
    {
	    dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	    *(unsigned int*)dst = color;
    }
}

t_draw  *init_draw(t_pixel p1, t_pixel p2)
{
    t_draw  *data;

    data = (t_draw *) malloc(sizeof(t_draw));
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

void    draw_line(t_pixel p_1, t_pixel p_2, t_data *data)
{
    p_1.x *= 20;
    p_1.y *= 20;
    p_2.x *= 20;
    p_2.y *= 20;

    t_draw  *c_data;
    int     i;

    c_data = init_draw(p_1, p_2);
    if (c_data->delta.x > c_data->delta.y)
    {
        i = 0;
        while (i < c_data->d)
        {
            my_mlx_pixel_put(data, c_data->current.x, c_data->current.y, 0xEC4B27);
            c_data->current.x += c_data->sign.x;
            c_data->r += c_data->delta.y;
            if (c_data->r >= c_data->delta.x)
                (c_data->current.y += c_data->sign.y, c_data->r -= c_data->delta.x);
            i++;
        }
    } 
    else {
        i = 0;
        while (i < c_data->d)
        {
            my_mlx_pixel_put(data, c_data->current.x, c_data->current.y, 0xEC4B27);
            c_data->current.y += c_data->sign.y;
            c_data->r += c_data->delta.x;
            if (c_data->r >= c_data->delta.y)
                (c_data->current.x += c_data->sign.x,c_data->r -= c_data->delta.y);
            i++;
        }

    }
}

void    draw(t_pixel **lines_map, t_data *data)
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
                draw_line(lines_map[y][x], lines_map[y][x+1],data);
            if (y != data->map->height - 1)
                draw_line(lines_map[y][x], lines_map[y+1][x],data);
            x++;
        }
        write(2,"a",2);
        y++;
    }
    mlx_put_image_to_window(data->mlx,data->win,data->img,0,0);
}