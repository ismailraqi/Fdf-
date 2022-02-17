# include "fdf.h"

t_lines    *new_line(t_pixel *f_pixel)
{
    t_lines *new_l;

    new_l = (t_lines *) malloc(sizeof(t_lines));
    if (!new_l)
        exit(EXIT_FAILURE);
    new_l->line = f_pixel;
    new_l->next = NULL;
    return (new_l);
}

void    cat_lines(t_lines **mother, t_lines *son)
{
    t_lines *curr;

    if (*mother)
    {
        curr = *mother;
        while (curr->next)
            curr = curr->next;
        curr->next = son;
    }
    else    *mother = son;
}

t_pixel     **lines_to_map(t_lines *lines, int size)
{
	t_pixel	**lines_map;
    t_lines *curr;
    int     i;
    
    lines_map = (t_pixel **) malloc(sizeof(t_pixel *) * size);
    if (!lines_map)
        exit(EXIT_FAILURE);
    curr = lines;
    i = 0;
    while (curr)
    {
        lines_map[i] = curr->line;
        i++;
        curr = curr->next;
    }
    return (lines_map);
}