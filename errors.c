/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:47:16 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/22 21:58:29 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(char *file_name)
{
	char **fdf;
	int	i;

	fdf = ft_split(file_name, '.');
	i = ft_strlen(fdf[1]);
	if (fdf[1][0] == 'f' && fdf[1][1] == 'd' && fdf[1][2] == 'f')
	{
		if (fdf[1][3] == 0x0)
			write (1, "Map read successfully!\n", 24);
	}
	else
		write (1, "Map error occured!\n", 20);
	free_str(fdf);
}