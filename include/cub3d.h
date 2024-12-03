#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include "struct.h"
#include <math.h>
#include <X11/X.h>
#include <X11/keysym.h>

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

#define WIDTH 1000
#define HEIGHT 1000
#define WIN_NAME "CUB3D"
#define TILE_SIZE 30
#define FOV 1
#define ROTATION_SPEED 0.2
#define PLAYER_SPEED 8

#define TRUE 1
#define FALSE 0

typedef enum e_direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
}	t_direction;

//parsing
//check_args
int     check_arguments(int argc, char **argv);
int     read_map(char *file);
int     check_first_args(char *str);
int     add_first_args(char *str);

//parsing
int     parsing(int argc, char **argv);

//real_map
int     init_real_map(void);
int     fill_real_map(void);

//path_finder
int     validate_map(t_map *map);

//init
int init_map(t_data *data);
int     init_data(void);

//exec/errors
int     err(char *str);
void    *err_null(char *str);

//Startgame
int		launcher(t_data *cub);
void init_game(t_data *cub); // provisoire

//RAYCATING

void cast_rays(t_data *cub);
float nor_angle(float angle);

//Rendering functions
void render(t_data *cub, int ray);


//key management
int exit_game(t_game *game);
int key_management(t_data *cub);
void key_press(int key, t_data *cub);
void	key_release(int key, t_data *cub);
void	hook(t_data *cub);

//free
int     free_data(t_data *data);

//debug
void    print_brut_map(void);
void    print_real_map(void);

//main
t_data  *get_data(void);
int     main(int argc, char **argv);

#endif