/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:04:52 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/17 19:09:55 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*s;

	s = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			s = str;
		str++;
	}
	if ((char)c == '\0')
		s = str;
	return ((char *)s);
}
