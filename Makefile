# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 12:07:08 by edogarci          #+#    #+#              #
#    Updated: 2023/05/23 14:02:30 by edogarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRC = ft_conv_funcs_01.c \
ft_conv_funcs_02.c \
ft_conv_funcs_03.c \
ft_conv_funcs_04.c \
ft_printf.c \
ft_itoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re