# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngragas <ngragas@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/04 20:29:14 by ngragas           #+#    #+#              #
#    Updated: 2020/11/18 19:52:42 by ngragas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-O3
SOURCES =	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	\
			ft_isprint.c	ft_toupper.c	ft_tolower.c	ft_strmapi.c	\
			ft_strlen.c		ft_strncmp.c	ft_memcmp.c						\
			ft_memchr.c		ft_strchr.c		ft_strrchr.c	ft_strnstr.c	\
			ft_strlcpy.c	ft_memcpy.c		ft_memccpy.c	ft_memmove.c	\
			ft_calloc.c		ft_bzero.c		ft_memset.c						\
			ft_strdup.c		ft_substr.c		ft_strlcat.c	ft_strjoin.c	\
			ft_strtrim.c	ft_split.c		\
			ft_atoi.c		ft_itoa.c		\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c
OBJECTS = $(SOURCES:.c=.o)
NAME = libft.a
HEADER = libft.h
RM = rm -f

.PHONY: all
all: $(NAME)
.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
.PHONY: re
re: fclean all

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $<
$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)