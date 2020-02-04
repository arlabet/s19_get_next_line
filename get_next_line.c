/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/04 20:19:41 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(char *str, int fd)
{
	char	*buff;
	int		ret;
	int		i;

	i = 0;
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		while (str[i])
		{
			if (str[i] == '\n')
				return (str);
			i++;
		}
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			i;

	i = 0;
	if (str == NULL)
		str = "";
	str = read_file(str, fd);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i])
	{
		if (i == 0)
		{
			if (!(*line = malloc(sizeof(char) * 1)))
				return (0);
			*line = "";
			return (1);
		}
		else
		{
			if (!(*line = malloc(sizeof(char) * (i + 1))))
				return (0);
			*line = ft_substr(str, 0, i);
			str = &str[i + 1];
			return (1);
		}
	}
	else
	{
		if (!(*line = malloc(sizeof(char) * 1)))
			return (0);
		*line = "";
	}
	return (0);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("poeme.txt", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%d\n", get_next_line(fd, &line));
		printf("%s\n", line);
	}
	return (0);
}
