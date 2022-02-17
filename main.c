/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:57:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/02/17 18:15:11 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	p_pixels(t_pixel *head)
{
	while (head->next)
		head = (printf("%3d %d\n",head->z,head->y), head->next);
}

int	main(int ac, char **av)
{
	t_pixel	*pixels;
	t_data	*data;
	t_pixel	*last;
	t_lines *lines;
	t_pixel	**lines_map;

	last = NULL;
	if (ac != 2)
		exit(EXIT_FAILURE);
	lines = get_list(av[1],&last);
	data = mlx_initializer();
	data->map = map_initializer(last);
	lines_map = lines_to_map(lines, data->map->height + 1);
	draw(lines_map,data);
	mlx_loop(data->mlx);
	//die("Done\n",EXIT_SUCCESS,&pixels);
	return (0);
	
}
