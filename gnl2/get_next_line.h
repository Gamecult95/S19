/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:14:03 by jdepierr          #+#    #+#             */
/*   Updated: 2023/05/31 15:09:22 by jdepierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(char *str);
int		ft_strchr(char *buff, char c);
char	*get_next_line(int fd);
char	*ft_bezero(char *str);
char	*ft_get_a_line(char *pre_line);
char	*ft_got_to_read(int fd);
char	*ft_strjoin(char *pre_line, char *buff);
char	*ft_get_a_rest(char *pre_line);

#endif