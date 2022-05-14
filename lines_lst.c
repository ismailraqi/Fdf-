/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:27:56 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/14 00:14:43 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lines	*new_line(t_pixel *f_pixel)
{
	t_lines	*new_l;

	new_l = (t_lines *) malloc(sizeof(t_lines));
	printf("Address new line %p\n", new_l);

	if (!new_l)
		exit(EXIT_FAILURE);
	new_l->line = f_pixel;
	new_l->next = NULL;
	return (new_l);
}

void	cat_lines(t_lines **mother, t_lines *son)
{
	t_lines	*curr;

	if (*mother)
	{
		curr = *mother;
		while (curr->next)
			curr = curr->next;
		curr->next = son;
	}
	else
		*mother = son;
}

t_pixel	**lines_to_map(t_lines *lines, int size)
{
	t_pixel	**lines_map;
	t_lines	*curr;
	t_lines	*next;
	int		i;

	lines_map = (t_pixel **) malloc(sizeof(t_pixel *) * size);
	printf("Address lines to map param %p\n", lines_map);
	if (!lines_map)
		exit(EXIT_FAILURE);
	curr = lines;
	i = 0;
	while (curr)
	{
		lines_map[i] = curr->line;
		i++;
		next = curr->next;
		free(curr);
		curr = next;
	}
	return (lines_map);
}

void	lines_clear(t_lines **head)
{
	t_lines	*current;
	t_lines	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		pixels_clear(&current->line);
		free(current);
		current = next;
	}
	*head = NULL;
}

void print_list(t_pixel **pixels, int i)
{
	printf("base adress: %p, id == %d\n", *pixels, i);
	t_pixel *c = *pixels;
	while (c)
		c = (printf("%d %d %d [%p]\n", c->x, c->y, c->z, c), c->next);
}

void	lines_map_clear(t_data *data)
{
	int		i;
	t_pixel	**pixels;
	t_pixel	*pixel;

	pixels = data->lines_map;
	i = -1;
	while (++i < data->map->height)
	{
		pixel = pixels[i];
		print_list(&pixel, i);
		if (pixel)
			pixels_clear(&pixel);
		// free(pixels[i]);
	}
	// pixels_clear(&pixels[i]);
	free(pixels);
	data->lines_map = NULL;
}