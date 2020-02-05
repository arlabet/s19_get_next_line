/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 09:57:35 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/04 19:35:09 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		free(res);
		return (0);
	}
	ft_strcpy(res, (char *)s1);
	ft_strcat(res, (char *)s2);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	r;

	r = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (len + start > ft_strlen(s) && start < ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (!(res = malloc(sizeof(char) * (len + 1))))
	{
		free(res);
		return (0);
	}
	while (r < len)
	{
		res[r] = s[start];
		r++;
		start++;
	}
	res[r] = '\0';
	return (res);
}
