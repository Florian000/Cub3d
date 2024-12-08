#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "libft/includes/libft.h"
#include "struct.h"
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdbool.h>

#define VALID 0
#define INVALID 1

#define N       78
#define S       83
#define E       69
#define W       87
#define EMPTY   -1

#define ERR_PARSING 20
#define ERR_LIBX    30
#define ERR_MALLOC  40

//GAME DEFINE
#define WIDTH 1000
#define HEIGHT 1000
#define WIN_NAME "CUB3D"
#define TILE_SIZE 64
#define FOV 1
#define ROTATION_SPEED 0.05
#define PLAYER_SPEED 8

#define PRINT_WIDTH 80
#define GREEN  "\033[1;32m"
#define RED "\033[1;31m" 
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

//parsing
//check_argsg
void     check_arguments(int argc, char **argv);
void     read_map(char *file);
int     check_first_args(char *str);
int     add_first_args(char *str);
int end_init_game(t_data *data);

//parsing
void     parsing(int argc, char **argv);

//real_map
int     init_real_map(void);
int     fill_real_map(void);

//path_finder
int     validate_map(t_map *map);

//init
int init_map(t_data *data);
int     init_data(void);
int init_text(t_texture *t);

//exec/errors
int     err(char *str);
void    *err_null(char *str);
void exit_print(void);

//Startgame
void welcome_print(void);
int		launcher(t_game *game);
int init_game(t_data *cub);

//RAYCATING

void cast_rays(t_ray *ray, t_player *player);
float h_inter(t_player *p, t_ray *ray, float angle);
float v_inter(t_player *p, t_ray *ray, float angle);
float nor_angle(float angle);

//Rendering functions
void render(t_ray *r, t_player *p, int ray);
void	my_mlx_pixel_put(void *mlx_img, int x, int y, int color);
t_texture	*get_texture(t_ray *r, int flag);
int	get_color(t_texture *texture, int x, int y);
double	get_xpm_x(t_texture *t, t_ray *ray);
int get_rgb(int R, int G, int B);

//key management
int	exit_game(t_game *game, char *str);
int key_press(int key, t_player *player);
int	key_release(int key, t_player *player);
void	hook(t_game *g);

//free
int     free_data(void);
int ft_free2(int res, char **str);

//debug
void    print_brut_map(void);
void    print_real_map(void);

//main
t_data  *get_data(void);
int     main(int argc, char **argv);

//utils
long	custom_hex_to_long(const char *str);

#endif