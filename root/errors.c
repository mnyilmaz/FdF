/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calypso <calypso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:47:16 by mervyilm          #+#    #+#             */
/*   Updated: 2023/04/18 01:42:27 by calypso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(char *file_name)
{
	char **fdf;
	
	fdf = ft_split(file_name, '.');
	if (fdf[1][0] == 'f' && fdf[1][1] == 'd' && fdf[1][2] == 'f' &&\
		fdf[1][3] == 0x0)
		write (1, "Map read successfully!\n", 24);
	else
		write (1, "Map error occured!\n", 20);
	free_str(fdf);
}

void	ac(int ac)
{
	if (ac != 2)
		return ;
}

