# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
SRCDIR = srcs
OBJDIR = objs
LIBFTDIR = include/libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = include/minilibx-linux
MLX = $(MLXDIR)/libmlx.a


SRC = $(shell find $(SRCDIR) -type f -name '*.c')
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) -lXext -lX11 -lm 

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(LIBFTDIR) -I$(MLXDIR) -I include -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re