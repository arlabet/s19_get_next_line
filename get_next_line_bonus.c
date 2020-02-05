/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/05 18:22:29 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*read_file(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	int		i;

	i = 0;
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

int	get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;
	char tmp[BUFFER_SIZE + 1];
	
	i = 0;
	if (BUFFER_SIZE <= 0 || !fd || read(fd, tmp, 0))
		return (-1);
	if (str[fd] == NULL || strchrn(str[fd]) == 0)
		str[fd] = read_file(str[fd], fd);
	if (str[fd] == NULL)
	{
		*line = ft_strdup("");
		return(0);
	}
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		str[fd] = ft_substr(str[fd], i + 1, ft_strlen(str[fd]));
		return (1);
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_substr(str[fd], 0, i);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (-1);
}
