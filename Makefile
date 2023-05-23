# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 12:07:08 by edogarci          #+#    #+#              #
#    Updated: 2023/05/22 17:27:09 by edogarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ./libft

SOURCE = ft_printf.c ft_conv_funcs_01.c

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCE:.c=.o)

libft:
	$(MAKELIBFT) -C $(LIBFT_DIR)

all: $(NAME) $(MAKELIBFT)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCE)
	gcc $(FLAGS) -c $(SOURCE)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re