# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvlachos <dvlachos@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 14:07:44 by dvlachos          #+#    #+#              #
#    Updated: 2024/11/27 15:36:23 by dvlachos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c prchar.c prhex.c prnum.c prpointer.c prstr.c ft_strlen.c prunsint.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

TEST_SRC = test_ft_printf.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_OUT = test_ft_printf.out

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

test: $(TEST_OUT)
	./$(TEST_OUT)

$(TEST_OUT): $(NAME) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) -L. -lftprintf -o $(TEST_OUT)

.PHONY: all clean fclean re
