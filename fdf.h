/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:03:56 by iraqi             #+#    #+#             */
/*   Updated: 2022/01/12 02:25:32 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include  <stdio.h>
# include "structs.h"

//      MAP HANDLING        //

t_pixel	*get_list(char *fname);
t_pixel	*split_delim(char *str, char d, t_cord *cord);
int	    get_hight_n_color(t_pixel *pixel, char *str, int size, char *base);

//      MAP HANDLING END    //



//      LIST HANDLING        //

t_pixel *new_pixel(int x,int y, int z, int color);
int	    add_pixel(t_pixel **head, char *str, t_cord *cord, int size);
void    pixels_clear(t_pixel **head);
void	cat_lst(t_pixel **mother, t_pixel *son);

//      LIST HANDLING END     //



//      UTILS HANDLING        //

int     ft_strlen(const char *s);
void    die(char *msg, int code, t_pixel **lst);

//      UTILS HANDLING END    //

# endif