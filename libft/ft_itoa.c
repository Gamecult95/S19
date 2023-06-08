/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:47:02 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/19 15:40:45 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lennb(int n)
{
	unsigned int	nb;
	size_t			cnt;

	cnt = 0;
	if (n == 0)
		cnt++;
	if (n < 0)
	{
		n = -n;
		cnt++;
	}
	nb = n;
	while (nb > 0)
	{
		cnt++;
		nb = nb / 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	size_t			i;
	unsigned int	nbr;

	i = 0;
	len = ft_lennb(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0 && i++ >= 0)
	{
		n = -n;
		str[0] = '-';
	}
	nbr = n;
	while (len > i)
	{
		str[len - 1] = "0123456789"[nbr % 10];
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
