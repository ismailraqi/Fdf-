/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:03:56 by iraqi             #+#    #+#             */
/*   Updated: 2022/02/06 14:19:18 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "structs.h"
# include "keycode.h"


# define WIDTH  1000
# define HEIGHT 1000 
void    draw(t_pixel **lines_map, t_data *data);
//      FILE HANDLING        //

t_lines	*get_list(char *fname,t_pixel **last);
t_pixel	*split_delim(char *str, t_cord *cord, t_pixel **last);
int     get_hight_n_color(t_pixel *pixel, char *str, int size, char *base);

//      FILE HANDLING END    //


//      INITIALIZING PROTOTYPES        //

t_data  *mlx_initializer(t_map *map);

//      INITIALIZING PROTOTYPES  END      //


//      LIST HANDLING        //

t_pixel *new_pixel(int x,int y, int z, int color);
t_pixel	*add_pixel(t_pixel **head, char *str, t_cord *cord, int size);
void    pixels_clear(t_pixel **head);
void    cat_lst(t_pixel **mother, t_pixel *son);
t_pixel	*ft_lstlast(t_pixel *lst);

//      LIST HANDLING END     //

//      MAP HANDLERS            //

t_map   *map_initializer(t_pixel *last);

//      MAP HANDLERS END        //


//      UTILS PROTOTYPES        //

int     ft_strlen(const char *s);
void    die(char *msg, int code, t_pixel **lst);

//      UTILS PROTOTYPES END    //


//      HOOKS PROTOTYPES        //

int 	mouse_hook(int button, int x, int y, void *param);
int		key_hook(int keycode, t_data *data);

//      HOOKS PROTOTYPES  END   //


/// UTILS
t_lines    *new_line(t_pixel *f_pixel);
void    cat_lines(t_lines **mother, t_lines *son);
t_pixel     **lines_to_map(t_lines *lines, int size);

# endif