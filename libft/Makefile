# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdepierr <jdepierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 17:01:17 by jdepierr          #+#    #+#              #
#    Updated: 2022/10/19 16:20:56 by jdepierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

BONUS		=	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra
NAME		= libft.a

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS:.c=.o)

.c.o		:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)		: $(OBJS)
				ar rcs $(NAME) $(OBJS)


all			: $(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean		: 
				$(RM) $(OBJS) $(BONUS_OBJS)


fclean		: clean
				$(RM) $(NAME)

re			: fclean $(NAME)

bonus		: $(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)
				
.PHONY		: all clean fclean re bonus