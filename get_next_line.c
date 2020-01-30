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


char	*read_line(char *str, int fd)
{
	char		*buff;
	int ret;
	static int i;
	
	if(!(buff = malloc(sizeof(char) * 2)))
		free(buff);
		
	while (buff[0] != '\n' && i < BUFFER_SIZE && i < OPEN_MAX 
		&& (ret = read(fd, buff, 1)) > 0)
	{
		str = ft_strjoin(str, buff);
		i++;
	}
	if (ret < 0)
		return(0);
	return (str);
}

int get_next_line(int fd, char **line)
{
	char *str;
	if(!(str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		free(str);
		return (-1);
	}
	if(!(*line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		free(*line);
		return (-1);
	}
	str = read_line(str, fd);
	ft_strcpy(*line, str);
	if (str[strlen(str) - 1] == '\n')
		return (1);
	return(0);
}

/*int		main(void)
{
	int		fd;
	char *line[1000];
	int i;

	i = 0;
	fd = open("poeme.txt", O_RDONLY);
		printf("%d\n", get_next_line(fd, line));
		printf("%s\n", *line);	
		printf("%d\n", get_next_line(fd, line));	
		printf("%s\n", *line);	
		printf("%d\n", get_next_line(fd, line));
		printf("%s\n", *line);	
		printf("%d\n", get_next_line(fd, line));
		printf("%s\n", *line);
	return (0);
}*/
