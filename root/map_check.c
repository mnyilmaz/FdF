/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervenuryilmaz <mervenuryilmaz@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:59:09 by mervyilm          #+#    #+#             */
/*   Updated: 2023/07/29 23:29:14 by mervenuryil      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_it_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-') && ft_isdigit(str[i + 1]))
		i++;
	else if (!ft_isdigit(str[i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_all_nums(char **map)
{
	int		h;
	int		w;
	char	**all_nums;

	h = 0;
	while (h < 11)
	{
		w = 0;
		all_nums = ft_split(map[w], ' ');
		while (all_nums[w])
		{
			if (is_it_number(all_nums[w]) == 0)
				return (0);
			w++;
		}
		free_str(all_nums);
		h++;
	}
	return (1);
}


int	check_map(char **map)
{
	if (check_all_nums(map) == 0 )
	{
		write (1, "\033[1;41m Kardeşim map hatalı diyoruz \033[0m\n", 42);
		exit(0);
	}
	return (1);
}