/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:30 by iraqi             #+#    #+#             */
/*   Updated: 2022/01/12 02:32:49 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

typedef struct s_args{
	char	*str;
	char	*tmp;
	int		j;
	int		r;
	int		bytes;
}	t_args;

char	*get_next_line(int fd);
int		ft_cleaner(t_args *args, char *c);
int		ft_get_line(t_args *args, char *c, int fd);
char	*ft_joiner(char *buffer, int bytes);
int		ft_strlen(const char *s);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_checker(t_args *args);

#endif