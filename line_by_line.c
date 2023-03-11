/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:08:38 by mervyilm          #+#    #+#             */
/*   Updated: 2023/03/11 12:08:29 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_height(char	*file_name)
{
	int	fd;
	int	height;
	char	*str;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while(str = get_next_line(fd))
	{
		free(str);
		height++;
	}
	close(fd);
	printf("%d", height);
	return(height);		
}

int	get_width(char	*file_name)
{
	return(1);
}
