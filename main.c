/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 01:57:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/01/12 02:45:52 by iraqi            ###   ########.fr       */
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

	if (ac != 2)
		exit(EXIT_FAILURE);
	pixels = get_list(av[1]);
	map = map_initializer(pixels);
	map_filler(&pixels, map);
	data = mlx_initializer(map);
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


	die("Done\n",EXIT_SUCCESS,&pixels);
	return (0);
	
}
