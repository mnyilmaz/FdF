/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:33:15 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/29 23:24:13 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	counter(char const *s, char c)
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

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_atoi(char *s)
{
	int	sign;
	int	res;
	int	i;

	res = 0;
	i = 0;
	while ((s[i] > 8 && s[i] < 20) || s[i] == ' ')
		i++;
	if (s[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != '\0')
	{
		res = res * 10 + (s[i] - 48);
		if (res * sign < -2147483648)
			return (0);
		else if (res * sign > 2147483647)
			return (-1);
		i++;
	}
	return (res * sign);
}
