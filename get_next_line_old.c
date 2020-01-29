/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/29 14:11:58 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	get_next_line(int fd, char **line)
{
	if (!(*line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	read(fd, *line, BUFFER_SIZE);
	return (1);
}

int	main(void)
{
	int		fd;
	char	*line[80];

	fd = open("numbers.dict", O_RDONLY);
	get_next_line(fd, line);
	printf("%s", *line);
}
