/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:21:03 by jdepierr          #+#    #+#             */
/*   Updated: 2023/06/02 15:31:39 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_a_line(char **str, char **line)
{
	size_t	len;
	char	*temp;

	len = 0;
	while (*str[len] != '\0' && *str[len] != '\n')
		len++;
	if (*str[len] == '\0')
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = 0x0;
	}
	if (*str[len] == '\n')
	{
		*line = ft_substr(*str, 0, len + 1);
		temp = ft_strdup(&(*str[len + 1]));
		free(*str);
		*str = temp;
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*statik[10240];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0';
		if (statik[fd] == 0)
			statik[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(statik[fd], buff);
			free(statik[fd]);
			statik[fd] = temp;
		}
		if (ft_strchr(statik[fd], '\n'))
			break ;
	}
	return (ft_get_a_line(&statik[fd], &line));
}
