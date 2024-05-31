# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:03:46 by pmihangy          #+#    #+#              #
#    Updated: 2024/05/04 08:29:38 by pmihangy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ARGUMENTS

CLIENT_NAME = client
SERVER_NAME = server
CLIENT_PATH = ./srcs/mandatory/client.c
CLIENT_UTILS_PATH = ./srcs/mandatory/client_utils.c
SERVER_PATH = ./srcs/mandatory/server.c
CLIENT_BONUS_PATH = ./srcs/bonus/client_bonus.c
CLIENT_UTILS_BONUS_PATH = ./srcs/bonus/client_utils_bonus.c
SERVER_BONUS_PATH = ./srcs/bonus/server_bonus.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

#RULES

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): make_printf
	$(CC) $(CFLAGS) $(CLIENT_PATH) $(CLIENT_UTILS_PATH) libftprintf.a  -o $(CLIENT_NAME)

$(SERVER_NAME): make_printf
	$(CC) $(CFLAGS) $(SERVER_PATH) libftprintf.a  -o $(SERVER_NAME)

make_printf: 
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a .

bonus: client_bonus server_bonus

client_bonus: make_printf
	$(CC) $(CFLAGS) $(CLIENT_BONUS_PATH) $(CLIENT_UTILS_BONUS_PATH) libftprintf.a  -o $(CLIENT_NAME)

server_bonus: make_printf
	$(CC) $(CFLAGS) $(SERVER_BONUS_PATH) libftprintf.a -o $(SERVER_NAME)

clean: 
	make -C ./ft_printf clean

fclean: clean
	make -C ./ft_printf fclean
	rm *.a server client

re: fclean all

.PHONY: all clean fclean re bonus client_bonus server_bonus
