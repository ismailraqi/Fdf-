/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:53:49 by iraqi             #+#    #+#             */
/*   Updated: 2022/01/12 02:47:31 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	w_counter(char const *src, char delimiter)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	if (src && !delimiter)
		return (1);
	if (!src)
		return (wc);
	if (src[i] != delimiter)
		wc++;
	while (src[i] != '\0')
	{
		if (src[i] != delimiter && src[i - 1] == delimiter)
			wc++;
		i++;
	}
	return (wc);
}

static int	ft_free(char **res, int row)
{
	if (res[row] == NULL)
	{
		while (res[--row])
			free(res[row]);
		free(res);
		return (1);
	}
	return (0);
}

static char	**w_creator(char **resu, const char *s, char delimiter)
{
	int		i;
	int		start;
	int		end;
	int		row;

	row = 0;
	i = 0;
	start = 0;
	end = 0;
	while (s[i] != '\0')
	{
		while (s[i] == delimiter && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != delimiter && s[i] != '\0')
			i++;
		end = i;
		if (start >= end)
			break ;
		resu[row] = ft_substr(s, start, (end - start));
		if (ft_free(resu, row++) == 1)
			return (NULL);
	}
	resu[row] = NULL;
	return (resu);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**res;

	if (!s)
		return (NULL);
	wc = w_counter(s, c);
	res = (char **) malloc (sizeof (char *) * (wc + 1));
	if (!res)
		return (NULL);
	res = w_creator(res, s, c);
	return (res);
}
