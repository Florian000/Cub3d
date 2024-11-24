# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 07:40:06 by jvittoz           #+#    #+#              #
#    Updated: 2023/12/08 14:58:07 by jvittoz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAG = -Wall -Werror -Wextra

HEADER = printf.h

SRC = ft_null.c ft_base.c ft_printf2.c ft_printf3.c ft_count.c  ft_printf.c

OBJ = ft_null.o ft_base.o ft_printf2.o ft_printf3.o ft_count.o  ft_printf.o

NAME = libftprintf.a

AR = ar -rcs

.c.o :
	${CC} ${FLAG} -c $< -o ${<:.c=.o}

${NAME} : ${OBJ}
	${AR} ${NAME} ${OBJ} 

all : ${NAME}

clean :
	rm -f ${OBJ} 

fclean : clean
	rm -f ${NAME}

re : fclean all


.PHONY : fclean all clean re

