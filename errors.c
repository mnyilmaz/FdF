/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:47:16 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/22 20:57:05 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(char *file_name)
{
	char **fdf;
	char *str;

	fdf = ft_split(file_name, '.');
	if ((fdf[1] != "fdf"))
		write (1, "Map error occured!\n", 20);
	else
		write (1, "Map read successfully!\n", 24);
}