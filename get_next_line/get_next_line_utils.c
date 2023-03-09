/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:10:53 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/02 18:03:21 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!*s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*alc;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	alc = (char *)malloc(sizeof(char) * (len + 1));
	if (!alc)
		return (NULL);
	while ((i < len) && (s[i + start] != 0))
	{
		alc[i] = s[i + start];
		i++;
	}
	alc[i] = 0;
	return (alc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*alc;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	alc = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (!alc)
		return (NULL);
	while (*s1)
	{
		alc[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		alc[i++] = *s2;
		s2++;
	}
	alc[i] = 0;
	return (alc);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mlc;
	char	*ptr;

	len = ft_strlen(s1);
	mlc = (char *)malloc(sizeof(char) * (len + 1));
	if (!mlc)
		return (NULL);
	ptr = mlc;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (mlc);
}

size_t	ft_strlen(const char *s)
{
	if (!*s)
		return (0);
	return (1 + ft_strlen(s + 1));
}
