/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 02:03:56 by iraqi             #+#    #+#             */
/*   Updated: 2022/05/17 18:57:04 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "structs.h"
# include "keycode.h"

# define WIDTH  1200
# define HEIGHT 900
# define M_WIDTH  400
# define M_HEIGHT 250

void		draw(t_pixel **lines_map, t_data *data);

//      FILE HANDLING        //

t_get_list	*get_list(char *fname, t_pixel **last);
t_pixel		*split_delim(char *str, t_cord *cord, t_pixel **last);
int			get_hight(t_pixel *pixel, char *str);

//      FILE HANDLING END    //

//      INITIALIZING PROTOTYPES        //

t_data		*mlx_initializer(void);
t_map		*map_initializer(t_pixel *last);
t_cam		*cam_initializer(t_data *data);
t_draw		*init_draw(t_pixel *p1, t_pixel *p2);

//      INITIALIZING PROTOTYPES  END      //

//      LIST HANDLING        //

t_pixel		*add_pixel(t_pixel **head, char *str, t_cord *cord);
void		pixels_clear(t_pixel **head);
void		cat_lst(t_pixel **mother, t_pixel *son);
void		cat_lines(t_lines **mother, t_lines *son);
t_lines		*new_line(t_pixel *f_pixel);

//      LIST HANDLING END     //

//      UTILS PROTOTYPES        //

int			ft_strlen(const char *s);
int			sign_test(int a, int b);
int			max(int a, int b);
//      UTILS PROTOTYPES END    //

//      HOOKS PROTOTYPES        //

int			mouse_hook(int button, int x, int y, void *param);
int			key_hook(int keycode, t_data *data);

//      HOOKS PROTOTYPES  END   //

//      UTILS
t_pixel		**lines_to_map(t_lines *lines, int size);
void		map_pixel_put(t_data *data, int x, int y, int color);
void		info_pixel_put(t_data *data, int x, int y, int color);
int			bernstein(double t);
t_pixel		wrapper(t_pixel p, t_data *data);
void		put_strings_to_image(t_data *data);
int			exit_hook(t_data *data);
void		lines_map_clear(t_data *data);
void		put_str(char *str);
//      ROTATION        //

void		x_rotation(float angle, int *y, int z);
void		y_rotation(float angle, int *x, int *z, int y);
void		z_rotation(float angle, int *y, int *x);

#endif