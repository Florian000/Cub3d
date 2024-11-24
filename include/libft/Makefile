# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 00:04:39 by jvittoz           #+#    #+#              #
#    Updated: 2024/10/03 21:04:35 by jvittoz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -fPIE

# Name of the library
NAME = libft.a

# Source and object files
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	  ft_isascii.c ft_isdigit.c ft_memchr.c ft_isalpha.c \
	  ft_memcmp.c ft_memcpy.c ft_strchr.c ft_memset.c \
	  ft_memmove.c ft_strdup.c ft_strlcat.c ft_strlen2.c \
	  ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	  ft_tolower.c ft_toupper.c ft_itoa.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	  ft_strjoin.c ft_strmapi.c ft_striteri.c ft_substr.c \
	  ft_space_split.c ft_free.c ft_dl_clear.c ft_dl_del.c \
	  ft_dl_new.c ft_dl_add_back.c ft_dl_size.c ft_strtrim.c \
	  ft_dl_last.c ft_split.c ft_dl_remove_from.c \
	  get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# Default rule to build the library
all: $(NAME)

# Rule to create the library archive
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to compile .c files into .o object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
