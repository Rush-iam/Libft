# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngragas <ngragas@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/04 20:29:14 by ngragas           #+#    #+#              #
#    Updated: 2020/11/04 22:03:00 by ngragas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
SOURCES = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c
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
	ar rcs $(NAME) $(OBJECTS)
