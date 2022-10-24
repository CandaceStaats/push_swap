# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cstaats <cstaats@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/02 08:30:46 by cstaats       #+#    #+#                  #
#    Updated: 2022/10/18 13:48:05 by cstaats       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = actionsA.c actionsB.c actionssimul.c errorchecks.c methods.c \
	radix.c utils.c utilscont.c main.c


OBS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBS)
	$(CC) -o $(NAME) $(OBS)

%.o: %.c push_swap.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

test: all
	gcc main.c -L. -lpush_swap 
