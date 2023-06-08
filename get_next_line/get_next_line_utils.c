/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:12:40 by jdepierr          #+#    #+#             */
/*   Updated: 2023/05/31 18:57:28 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0x0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*temp;

	if (!s1 || !s2)
		return (0x0);
	temp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (0x0);
	str = temp;
	while (*s1 != '\0')
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*temp = *s2;
		temp++;
		s2++;
	}
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*temp;

	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0x0);
	str = temp;
	while (start < len)
	{
		*temp = s[start];
		start++;
		temp++;
	}
	*temp = '\0';
	return (str);
}

char	*ft_strdup(char *str)
{
	char	*s;
	char	*temp;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (!str)
		return (0x0);
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0x0);
	s = temp;
	while (str[i])
	{
		*temp = str[i];
		i++;
		temp++;
	}
	*temp = '\0';
	return (s);
}
