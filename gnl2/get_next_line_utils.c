/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:07 by jdepierr          #+#    #+#             */
/*   Updated: 2023/06/02 16:28:16 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_bezero(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
		str[i++] = '\0';
	return (str);
}

int	ft_strchr(char *buff, char c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(buff))
	{
		if (buff[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *pre_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!pre_line)
	{
		pre_line = malloc(sizeof(char) * 1);
		pre_line = ft_bezero(pre_line);
	}
	if (!pre_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(pre_line) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (pre_line[++i] != '\0')
		str[i] = pre_line[i];
	while (buff[++j] != '\0')
		str[i + j] = buff[j];
	str[i + j] = '\0';
	return (str);
}
