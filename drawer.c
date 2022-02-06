# include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_line(t_pixel p_1, t_pixel p_2, t_data *data)
{
    int dx, dy, p ,x ,y;

    p_1.x *= 20;
    p_1.y *= 20;
    p_2.x *= 20;
    p_2.y *= 20;
    dx = p_2.x - p_1.x;
    dy = p_2.y - p_1.y;
    x = p_1.x;
    y = p_1.y;
    p = 2*dy-dx;


    while (x < p_2.x)
    {
        if (p >= 0)
        {
            my_mlx_pixel_put(data, x, y,0xEC4B27);
            y=y+1;
            p=p+2*dy-2*dx;
        } else {
            my_mlx_pixel_put(data, x, y,0xEC4B27);
            p=p+2*dy;
        }
        x = x + 1;
    }
}

void    draw(t_pixel **lines_map, t_data *data)
{
    int y;
    int x;

    y = 0;
    while (y < data->map->height - 1)
    {
        x = 0;
        while (x < data->map->width - 1)
        {
            draw_line(lines_map[y][x], lines_map[y][x+1],data);
            draw_line(lines_map[y][x], lines_map[y+1][x],data);
            //printf("point 1 x = %d | y = %d \n",lines_map[y][x].x,lines_map[y][x].y);
            x++;
        }
        y++;
    }
    //draw_line(lines_map[1][4], lines_map[1][4],data);
    mlx_put_image_to_window(data->mlx,data->win,data->img,0,0);
}