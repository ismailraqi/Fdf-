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
	while (head)
		head = (printf("%3d",head->z), head->next);
}

int	main(int ac, char **av)
{
	t_pixel	*pixels;

	if (ac != 2)
		exit(EXIT_FAILURE);
	pixels = get_list(av[1]);
	p_pixels(pixels);
	pixels_clear(&pixels);
	die("Done\n",EXIT_SUCCESS,&pixels);
	return (0);
	
}


