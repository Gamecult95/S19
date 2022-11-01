/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:18:20 by jdepierr          #+#    #+#             */
/*   Updated: 2022/10/24 15:12:49 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_printchar(int c);
size_t	ft_printstr(char *str);
size_t	ft_printaddr(unsigned long int nbr);
size_t	ft_printnbr(int nbr);
size_t	ft_printunbr(unsigned int nbr);
size_t	ft_printuhex(unsigned int nbr);
size_t	ft_printuhex_up(unsigned int nbr);

#endif