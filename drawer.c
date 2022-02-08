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

void    draw_line(t_pixel p_1, t_pixel p_2, t_data *data)
{
    //int k,steps,p0,p,dx,dy,x,y;
    p_1.x *= 5;
    p_1.y *= 5;
    p_2.x *= 5;
    p_2.y *= 5;
    // dx=abs(p_2.x-p_1.x);
    // dy=abs(p_2.y-p_1.y);
    // x=p_1.x;
    // y=p_1.y;
    // if(dx>dy)
    //     steps=dx;
    // else
    //     steps=dy;
    // my_mlx_pixel_put(data, x, y,0xEC4B27);
    // p0=2*dy-dx;
    // p=p0;
    // for(k=0;k<steps;k++)
    // {
    //     x=x+1;
    //     if(p<0)
	//         p=p+(2*dy);
    //     else
    //     {
	//         y=y+1;
	//         p=p+2*dy-2*dx;
	//     }
    //     y=y+1;
	//     p=p+2*dy-2*dx;
    //     my_mlx_pixel_put(data, x, y,0xEC4B27);
    // }
    int Dx = p_2.x - p_1.x;
    int Dy = p_2.y - p_1.y;

    //# Increments
    int Sx = Sign(Dx); 
    int Sy = Sign(Dy);

    //# Segment length
    Dx = abs(Dx); 
    Dy = abs(Dy); 
    int D = MAX(Dx, Dy);

    //# Initial remainder
    double R = D / 2;

    int X = p_1.x;
    int Y = p_1.y;
    if(Dx > Dy)
    {   
        //# Main loop
        for(int I=0; I<D; I++)
        {   
            my_mlx_pixel_put(data, X, Y,0xEC4B27);
            //# Update (X, Y) and R
            X+= Sx; R+= Dy; //# Lateral move
            if (R >= Dx)
            {
                Y+= Sy; 
                R-= Dx; //# Diagonal move
            }
        }
    }
    else
    {   
        //# Main loop
        for(int I=0; I<D; I++)
        {    
            my_mlx_pixel_put(data, X, Y,0xEC4B27);
            //# Update (X, Y) and R
            Y+= Sy; 
            R+= Dx; //# Lateral move
            if(R >= Dy)
            {    
                X+= Sx; 
                R-= Dy; //# Diagonal move
            }
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
            //printf("point 1 x = %d | y = %d \n",lines_map[y][x].x,lines_map[y][x].y);
            x++;
        }
        printf("y == %d\n", y);
        y++;
    }
    //draw_line(lines_map[1][4], lines_map[1][4],data);
    mlx_put_image_to_window(data->mlx,data->win,data->img,0,0);
}