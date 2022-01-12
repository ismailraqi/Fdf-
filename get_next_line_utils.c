/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:37 by iraqi             #+#    #+#             */
/*   Updated: 2021/12/04 23:31:15 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	copy = (char *) malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*fdest;
	unsigned const char	*fsrc;
	size_t				i;
	int					d;

	if (dest == NULL && src == NULL)
		return (NULL);
	fdest = (unsigned char *)dest;
	fsrc = (const unsigned char *)src;
	i = n;
	d = 0;
	while (i > 0)
	{
		fdest[d] = fsrc[d];
		d++;
		i--;
	}
	return (dest);
}

char	*ft_checker(t_args *args)
{
	if (args->j == 0 && args->bytes == 0)
		return (free(args->str), NULL);
	(args->str)[args->j + args->bytes] = '\0';
	args->tmp = ft_strdup(args->str);
	free(args->str);
	args->str = args->tmp;
	return (args->str);
}
