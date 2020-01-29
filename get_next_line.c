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

char	*get_next_line(char *str, int fd)
{
	char		*buff;
	static int i;

	if(!(buff = malloc(sizeof(char) * 2)))
		return (0);
	while (buff[0] != '\n' && i < BUFFER_SIZE)
	{
		read(fd, buff, 1);
		str = ft_strjoin(str, buff);
		i++;
	}
	printf("%s", str);
	return (str);
}

int		main(void)
{
	int		fd;
	char line[1000];
	
	fd = open("poeme.txt", O_RDONLY);
	get_next_line(line, fd);
	get_next_line(line, fd);
	get_next_line(line, fd);
	return (0);
}
