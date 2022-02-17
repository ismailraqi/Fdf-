
#include "fdf.h"


int tt (t_pixel p_1, t_pixel p_2, t_data *data)
{
    int Dx = p_2.x - p_1.x;
    int Dy = p_2.y - p_1.y;

    //# Increments
    int Sx = Sign(Dx); 
    int Sy = Sign(Dy);

    //# Segment length
    Dx = Dx; 
    Dy = Dy; 
    int D = MAX(Dx, Dy);

    //# Initial remainder
    double R = D / 2;

    int X = p_1.x;
    int Y = p_1.y;


}