/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:57:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/02/06 15:40:15 by iraqi            ###   ########.fr       */
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
	t_map	*map;
	t_data	*data;
	t_pixel	*last;
	t_lines *lines;
	t_pixel	**lines_map;

	last = NULL;
	if (ac != 2)
		exit(EXIT_FAILURE);
	lines = get_list(av[1],&last);
	map = map_initializer(last);
	lines_map = lines_to_map(lines, map->height + 1);
	data = mlx_initializer(map);
	// for (int i = 0; i < map->height; i++)
	// {
	// 	for (int j = 0; j < map->width; j++)
	// 	{
	// 		/* code */
	// 	printf("y == %d  count == %d\n", lines_map[i][j].y, lines_map[i][j].x);
	// 	}
	// 	printf("########################\n");
		
	// }
	
	//draw(lines_map,data);
	//printf("%d %d %d \n", data->map->map_size,data->map->width,data->map->height);
	//mlx_loop(data->mlx);
	// int i = 0;
	// int z = 18;
	// while (i <= map->map_size)
	// {
	// 	printf("%3d ",map->map_cordinates[i]);
	// 	if(i == 18 || i == z)
	// 	{
	// 		printf("\n");
	// 		z += 19;
	// 	}
	// 	i++;
	// }
	// DRAW ALGO HERE //
	//die("Done\n",EXIT_SUCCESS,&pixels);
	return (0);
	
}
