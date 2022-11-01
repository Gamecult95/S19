/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:33:14 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/24 16:40:12 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_len(long int n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_print_nbr(long int n)
{
	if (n > 9)
	{
		ft_print_nbr(n / 10);
		n = n % 10;
	}
	ft_printchar(n + '0');
}

size_t	ft_printnbr(int nbr)
{
	size_t		cnt;
	long int	n;

	cnt = 0;
	n = nbr;
	if (nbr == 0)
	{
		write(1, "0", 1);
		cnt++;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		cnt = 1;
		n = -n;
	}
	cnt += ft_len(n);
	if (n > 0)
		ft_print_nbr(n);
	return (cnt);
}
