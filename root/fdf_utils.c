/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:33:15 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/17 16:52:56 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	counter(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	cnt;
	char	**alc;

	i = 0;
	if (!s)
		return (0);
	cnt = counter(s, c);
	alc = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!alc)
		return (0);
	while (i < cnt)
	{
		while (*s == c)
		s++;
		len = 0;
		while (s[len] != c && s[len])
			len++;
		alc[i++] = ft_substr(s, 0, len);
		s = s + len;
	}
	alc[i] = 0;
	return (alc);
}

void	free_str(char **str)
{
	int	i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	cal = malloc(count * size);
	if (!cal)
		return (0);
	ft_bzero(cal, count * size);
	return (cal);
}