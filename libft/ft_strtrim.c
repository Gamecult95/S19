/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:57:29 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/19 13:32:07 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(char const *set, char const c)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len_s1;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	while (ft_cmp(set, s1[i]) > 0)
		i++;
	while (ft_cmp(set, s1[len_s1 - 1]) > 0 && len_s1 > i)
		len_s1--;
	str = malloc(sizeof(char) * (len_s1 - i + 1));
	if (!str)
		return (NULL);
	while (i < len_s1)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
