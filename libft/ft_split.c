/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:04:14 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/20 16:17:53 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_lst(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

static size_t	ft_wordcnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (cnt);
}

static char	*ft_word(char const *s, char c)
{
	size_t	i;
	char	*str;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_split_split(char const *s, char c, char **array)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != c && *s != '\0')
		{	
			temp = ft_word(s, c);
			if (!temp)
				return (ft_free_lst(array, i));
			array[i] = temp;
			i++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_wordcnt(s, c) + 1));
	if (!array)
		return (NULL);
	array = ft_split_split(s, c, array);
	return (array);
}
