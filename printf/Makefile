# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 16:18:03 by jdepierr          #+#    #+#              #
#    Updated: 2022/10/24 14:33:45 by jdepierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printaddr.c \
				ft_printchar.c \
				ft_printf.c \
				ft_printnbr.c \
				ft_printstr.c \
				ft_printuhex_up.c \
				ft_printuhex.c \
				ft_printunbr.c \

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra
NAME		= libftprintf.a

OBJS		= $(SRCS:.c=.o)

.c.o		:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)		: $(OBJS)
				ar rcs $(NAME) $(OBJS)

all 		: $(OBJS)
				ar rcs $(NAME) $(OBJS)

clean		:
				$(RM) $(OBJS)

fclean		: clean
				$(RM) $(NAME)

re			: fclean $(NAME)

.PHONY		: all clean flclean re
	