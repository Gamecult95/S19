/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuhex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:19:30 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/24 15:55:05 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lenhex(unsigned int nbr)
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

static void	ft_putuhex_up(unsigned int nbr)
{
	if (nbr < 16)
		ft_printchar("0123456789ABCDEF"[nbr]);
	else
	{
		ft_putuhex_up(nbr / 16);
		ft_putuhex_up(nbr % 16);
	}
}

size_t	ft_printuhex_up(unsigned int nbr)
{
	size_t	cnt;

	if (nbr == 0)
		return (ft_printchar('0'));
	cnt = ft_lenhex(nbr);
	ft_putuhex_up(nbr);
	return (cnt);
}
