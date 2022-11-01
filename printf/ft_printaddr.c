/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:18:24 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/24 16:45:57 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lenhex(unsigned long int nbr)
{
	size_t	len;

	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

static void	ft_printaddr_nbr(unsigned long int nbr)
{
	if (nbr < 16)
		ft_printchar("0123456789abcdef"[nbr]);
	else
	{
		ft_printaddr_nbr(nbr / 16);
		ft_printaddr_nbr(nbr % 16);
	}
}

size_t	ft_printaddr(unsigned long int nbr)
{
	size_t	cnt;

	cnt = 0;
	cnt += ft_printstr("0x");
	if (nbr == 0)
	{
		write(1, "0", 1);
			cnt++;
	}
	cnt += ft_lenhex(nbr);
	if (nbr > 0)
		ft_printaddr_nbr(nbr);
	return (cnt);
}
