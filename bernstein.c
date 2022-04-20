/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bernstein.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:42:43 by iraqi             #+#    #+#             */
/*   Updated: 2022/04/19 23:59:48 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	bernstein(double t)
{
	int	r;
	int	g;
	int	b;

	r = 2 * (int)floor((1. - t) * 255.);
	g = 2 * (int)floor(255 * 2 * t * (1. - t));
	b = 2 * (int)floor(2 * 255 * t * t);
	return (r << 16 | g << 8 | b);
}
