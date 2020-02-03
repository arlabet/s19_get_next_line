/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/29 20:01:41 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	char *buff;
	*line = "";
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return(0);
	read(fd, buff, BUFFER_SIZE);
	*line = ft_strjoin(*line, buff);
	printf("%s", *line);
	return (1);
}

int		main(void)
{
	int		fd;
	char *line[80];

	fd = open("poeme.txt", O_RDONLY);
	get_next_line(fd, line);
	return (0);
}
