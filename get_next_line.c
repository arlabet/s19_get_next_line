/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/05 17:57:08 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*read_file(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	int		i;
	char	*temp;

	i = 0;
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = str;
		str = ft_strjoin(temp, buff);
		free(temp);
		while (str[i])
		{
			if (str[i] == '\n')
				return (str);
			i++;
		}
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			i;
	char 		*tmp;
	
	i = 0;
	if (BUFFER_SIZE <= 0 || !fd)
		return (-1);
	if (str == NULL || strchrn(str) == 0)
		str = read_file(str, fd);
	if (str == NULL)
	{
		*line = ft_strdup("");
		return(0);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_substr(str, 0, i);
		tmp = str;
		str = ft_substr(tmp, i + 1, ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	else if (str[i] == '\0')
	{
		*line = ft_substr(str, 0, i);
		free(str);
		return (0);
	}
	return (-1);
}

int main (void)
{
	int fd;
	char *line;
	fd = open("poeme.txt", O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		printf("%s\n", line);
	}
	printf("%s\n", line);
	return (0);
}