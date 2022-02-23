
// #include "fdf.h"


// int tt (t_pixel p_1, t_pixel p_2, t_data *data)
// {
//     int Dx = p_2.x - p_1.x;
//     int Dy = p_2.y - p_1.y;

//     //# Increments
//     int Sx = Sign(Dx); 
//     int Sy = Sign(Dy);

//     //# Segment length
//     Dx = Dx; 
//     Dy = Dy; 
//     int D = MAX(Dx, Dy);

//     //# Initial remainder
//     double R = D / 2;

//     int X = p_1.x;
//     int Y = p_1.y;


// }










// void    draw_2(t_pixel p1, t_pixel p2, t_data *data)
// {

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
//         my_mlx_pixel_put(data, c_data->current.x, c_data->current.y, 0xEC4521);
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