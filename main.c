/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:57:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/25 00:41:17 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	file_checker(char *fname)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_pixel	*last;
	t_lines	*lines;

	last = NULL;
	if (ac != 2 || !file_checker(av[1]))
		exit(EXIT_FAILURE);
	data = mlx_initializer();
	lines = get_list(av[1], &last);
	data->map = map_initializer(last);
	free(last);
	data->cam = cam_initializer(data);
	data->lines_map = lines_to_map(lines, data->map->height + 1);
	lines_clear(&lines);
	draw(data->lines_map, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
