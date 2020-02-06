/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:04:33 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/06 19:50:29 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*read_file(char *str, int fd);
int			strchrn(char *str);
char		*ft_strdup(const char *src);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#endif
