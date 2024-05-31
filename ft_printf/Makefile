# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:30:20 by pmihangy          #+#    #+#              #
#    Updated: 2024/03/25 09:56:21 by pmihangy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c 
OBJS = ft_printf.o ft_printf_utils.o ft_printf_utils2.o
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs

all : $(NAME)

$(NAME) : libft $(OBJS)
	$(AR) $(NAME) $(OBJS)

libft : 
	make -C ./libft 
	cp ./libft/libft.a .
	mv libft.a $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
 
clean : 
	make -C ./libft clean
	rm -f *.o

fclean : clean
	make -C ./libft fclean
	rm -f *.a

re : fclean all

# run : 
# 	cc main.c -L. libftprintf.a

.PHONY : all libft clean fclean re
