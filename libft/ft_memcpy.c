/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:59:31 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/17 18:50:05 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*srce;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dest = (char *)dst;
	srce = (const char *)src;
	while (i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	dst = (void *)dest;
	return (dst);
}
