#include "fdf.h"

t_pixel *new_pixel(int x,int y, int z, int color)
{
	t_pixel *new_p;

	new_p = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new_p)
		return (NULL);
	new_p->x = 0;
	new_p->y = 0;
	new_p->z = 0;
	new_p->color = 0;
	new_p->next = NULL;
	return (new_p);
}

int	add_pixel(t_pixel **head, t_pixel *new)
{
	t_pixel	*current;

	if (!head || !new) 
		return (-1);
	if (!*head)
		return (*head = new, 0);
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new;
	return (0);
}

void    pixels_clear(t_pixel **head)
{
    t_pixel	*current;
	t_pixel *next;

    current = *head;

    while (current)
    {		
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void    die(char *msg, int code, t_pixel **lst)
{
    if (lst)
        pixels_clear(lst);
    if (msg)
        write(2, msg, ft_strlen(msg));
    exit(code);
}