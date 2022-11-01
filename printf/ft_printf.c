/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:14:02 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/24 15:10:35 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list lst, const char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(lst, int));
	if (format == 's')
		len += ft_printstr(va_arg(lst, char *));
	if (format == 'p')
		len += ft_printaddr(va_arg(lst, unsigned long int));
	if (format == 'd')
		len += ft_printnbr(va_arg(lst, int));
	if (format == 'i')
		len += ft_printnbr(va_arg(lst, int));
	if (format == 'u')
		len += ft_printunbr(va_arg(lst, unsigned int));
	if (format == 'x')
		len += ft_printuhex(va_arg(lst, unsigned int));
	if (format == 'X')
		len += ft_printuhex_up(va_arg(lst, unsigned int));
	if (format == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	len;
	size_t	i;
	va_list	lst;

	len = 0;
	i = 0;
	va_start (lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_formats(lst, str[i]);
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
