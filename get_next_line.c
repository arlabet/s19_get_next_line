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
	int ret;
	static int i;

	ret = 1;
	if(!(buff = malloc(sizeof(char) * 2)))
		return (0);
	while (buff[0] != '\n' && i < BUFFER_SIZE && (ret > 0))
	{
		ret = read(fd, buff, 1);
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
	int i;

	i = 0;
	fd = open("poeme.txt", O_RDONLY);
	while (i++ < 100000)
		get_next_line(line, fd);
	
	return (0);
}
