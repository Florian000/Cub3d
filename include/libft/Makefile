# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:09:48 by fgranger          #+#    #+#              #
#    Updated: 2024/12/06 20:08:55 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

DIR_GNL	=	srcs/ft_gnl/
DIR_IS	=	srcs/ft_is/
DIR_LST	=	srcs/ft_lst/
DIR_MEM	=	srcs/ft_mem/
DIR_PRINTF =	srcs/ft_printf/
DIR_PUT	=	srcs/ft_put/
DIR_STR	=	srcs/ft_str/
DIR_TO	=	srcs/ft_to/

SRCS 		=		$(DIR_TO)ft_atoi.c \
				$(DIR_TO)ft_itoa.c \
				$(DIR_TO)ft_tolower.c \
				$(DIR_TO)ft_toupper.c \
				$(DIR_STR)ft_split.c \
				$(DIR_STR)ft_strchr.c \
				$(DIR_STR)ft_strdup.c \
				$(DIR_STR)ft_striteri.c \
				$(DIR_STR)ft_strjoin.c \
				$(DIR_STR)ft_strlcat.c \
				$(DIR_STR)ft_strlcpy.c \
				$(DIR_STR)ft_strlen.c \
				$(DIR_STR)ft_strmapi.c \
				$(DIR_STR)ft_strncmp.c \
				$(DIR_STR)ft_strnstr.c \
				$(DIR_STR)ft_strrchr.c \
				$(DIR_STR)ft_strtrim.c \
				$(DIR_STR)ft_substr.c \
				$(DIR_PUT)ft_putchar_fd.c \
				$(DIR_PUT)ft_putendl_fd.c \
				$(DIR_PUT)ft_putnbr_fd.c \
				$(DIR_PUT)ft_putstr_fd.c \
				$(DIR_PRINTF)ft_printf.c \
				$(DIR_PRINTF)ft_conversions.c \
				$(DIR_PRINTF)ft_conversions2.c \
				$(DIR_PRINTF)ft_put_with_printedcount.c \
				$(DIR_MEM)ft_bzero.c \
				$(DIR_MEM)ft_calloc.c \
				$(DIR_MEM)ft_memchr.c \
				$(DIR_MEM)ft_memcmp.c \
				$(DIR_MEM)ft_memcpy.c \
				$(DIR_MEM)ft_memmove.c \
				$(DIR_MEM)ft_memset.c \
				$(DIR_IS)ft_isalnum.c \
				$(DIR_IS)ft_isalpha.c \
				$(DIR_IS)ft_isascii.c \
				$(DIR_IS)ft_isdigit.c \
				$(DIR_IS)ft_isprint.c \
				$(DIR_IS)ft_isspace.c \
				$(DIR_LST)ft_lstadd_back.c \
				$(DIR_LST)ft_lstadd_front.c \
				$(DIR_LST)ft_lstclear.c \
				$(DIR_LST)ft_lstdelone.c \
				$(DIR_LST)ft_lstiter.c \
				$(DIR_LST)ft_lstlast.c \
				$(DIR_LST)ft_lstmap.c \
				$(DIR_LST)ft_lstnew.c \
				$(DIR_LST)ft_lstsize.c \
				$(DIR_GNL)get_next_line.c \
				$(DIR_GNL)get_next_line_utils.c \
				
OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	-I includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.c.o :	
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
