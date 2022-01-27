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
# include "structs.h"
#include <stdio.h>

void	ft_putstr(char *s);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int     ft_atoi(char *str);
void    init_map(t_data *data, char *f_name);
int     ft_strlen(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
t_pixel *new_pixel(int x,int y, int z, int color);
int	    add_pixel(t_pixel **head, t_pixel *new);

# endif