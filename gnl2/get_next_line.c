/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:13:29 by jdepierr          #+#    #+#             */
/*   Updated: 2023/06/02 17:22:29 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_a_rest(char *pre_line)
{
	char	*rest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	rest = malloc(sizeof(char) * (ft_strlen(pre_line) + 1));
	while (pre_line[i] != '\n')
		i++;
	i++;
	while (pre_line[i] != '\0')
	{
		rest[j] = pre_line[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	pre_line = ft_bezero(pre_line);
	pre_line = ft_strjoin(pre_line, rest);
	free(rest);
	return (pre_line);
}

char	*ft_get_a_line(char *pre_line)
{
	char	*line;
	size_t	i;

	i = 0;
	line = malloc(sizeof(char) * (ft_strlen(pre_line) + 2));
	if (!line)
		return (NULL);
	while (pre_line[i] != '\0' && pre_line[i] != '\n')
	{
		line[i] = pre_line[i];
		i++;
	}
	if (pre_line[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_got_to_read(int fd)
{
	char	*buff;
	char	*str;
	int		bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_read = read(fd, buff, BUFFER_SIZE);
	buff[bytes_read] = '\0';
	while (bytes_read != 0 && ft_strchr(buff, '\n') > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		str = ft_strjoin(str, buff);
		free(buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	statik[BUFFER_SIZE + 1];
	char		*line;
	char		*pre_line;
	char		*temp;
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pre_line = ft_got_to_read(fd);
	line = ft_get_a_line(pre_line);
	if (ft_strchr(pre_line, '\n') < 1)
	{
		temp = ft_get_a_rest(pre_line);
		while (pre_line[i] != '\0')
		{
			statik[i] = temp[i];
			i++;
		}
		statik[i] = '\0';
	}
	return (line);
}
