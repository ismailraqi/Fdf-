/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:57:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/03/06 20:58:34 by iraqi            ###   ########.fr       */
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

	last = NULL;
	if (ac != 2)
		exit(EXIT_FAILURE);
	lines = get_list(av[1],&last);
	data = mlx_initializer();
	data->map = map_initializer(last);
	data->cam = cam_initializer(data);
	data->lines_map = lines_to_map(lines, data->map->height + 1);
	draw(data->lines_map,data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	//die("Done\n",EXIT_SUCCESS,&pixels);
	return (0);
	
}
