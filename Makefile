# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:07:44 by dvlachos          #+#    #+#              #
#    Updated: 2024/11/19 14:09:06 by dvlachos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -r $@ $?

%.o: %.c 
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
