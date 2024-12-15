/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:03:41 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/15 13:41:12 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//includes
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/includes/libft.h"
# include "struct.h"
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

//defines parsing
# define VALID			0
# define INVALID		1
# define N				78
# define S				83
# define E				69
# define W				87
# define EMPTY			-1
# define ERR_PARSING	20
# define ERR_LIBX		30
# define ERR_MALLOC		40

//define game
# define WIDTH			1000
# define HEIGHT			1000
# define WIN_NAME		"CUB3D"
# define TILE_SIZE		64
# define FOV			1
# define ROTATION_SPEED	0.03
# define PLAYER_SPEED	5

//define print term
# define PRINT_WIDTH	80
# define GREEN			"\033[1;32m"
# define RED			"\033[1;31m" 
# define YELLOW			"\033[1;33m"
# define BLUE			"\033[1;34m"
# define RST			"\033[0m"

//parsing
void		parsing(int argc, char **argv);
void		check_arguments(int argc, char **argv);
void		read_map(char *file);
int			check_first_args(char *str);
int			check_files_open(t_data *data);
int			add_first_args(char *str);
int			end_init_game(t_data *data);
void		check_arguments(int argc, char **argv);
int			init_real_map(void);
void		validate_map2(int *i, int *j, int *player_x, int *player_y);
int			fill_real_map(void);
int			validate_map(t_map *map);
int			init_map(t_data *data);
int			ft_isnotdigit(char c);
int			init_data(void);
int			add_color_to_data(char **nb, char *color);
int			add_texture(char *str);
int			init_map(t_data *data);
int			flood_fill_check(int **map, int height, int length, t_pathf f);
int			check_nb_player(t_data *data);
int			check_first_args(char *str);
int			check_color(char **nb);

//init
t_data		*get_data(void);
int			get_rgb(int R, int G, int B);

//print welcome and exit message on term
void		exit_print(void);
void		welcome_print(void);

//game
int			launcher(t_game *game);
int			key_press(int key, t_player *player);
int			key_release(int key, t_player *player);
void		hook(t_game *g);

//Ray casting
void		cast_rays(t_ray *ray, t_player *player);
float		h_inter(t_player *p, t_ray *ray, float angle);
float		v_inter(t_player *p, t_ray *ray, float angle);
float		nor_angle(float angle);
void		render(t_ray *r, t_player *p, int ray);
void		my_mlx_pixel_put(void *mlx_img, int x, int y, int color);
t_texture	*get_texture(t_ray *r, int flag);
int			get_color(t_texture *texture, int x, int y);
double		get_xpm_x(t_texture *t, t_ray *ray);

//exit and free
int			exit_game(char *str);
void		free_data(t_data *data);
int			ft_free2(int res, char **str);
void		free_mlx(t_game *g);
int			free_texture(t_texture *t);

#endif