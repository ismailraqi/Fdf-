/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_into_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:01:00 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/23 01:35:52 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_strings_to_image(t_data *data)
{
	int	start;
		
	start = WIDTH - M_WIDTH;

	mlx_string_put(data->mlx, data->win, 800, 500 , 0x00adf10f, "Hellcfhdzfhzdfhdzfhzdo");
	write(2, "a", 1);
}
