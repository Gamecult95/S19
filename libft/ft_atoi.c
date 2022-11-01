/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:25:26 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/21 12:09:59 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				neg;
	long int		nb;
	long int		temp;

	neg = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		temp = nb;
		nb = (nb * 10) + (*str - '0');
		str++;
		if (nb < temp && neg == 1)
			return (-1);
		if (nb < temp && neg == -1)
			return (0);
	}
	return (neg * (int)nb);
}
