/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:03:41 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 19:47:24 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_data	t_data;

typedef struct s_map
{
	int		height;
	int		length;
	int		pos_x;
	int		pos_y;
	char	**brut_map;
	int		**real_map;
}	t_map;

typedef struct t_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

typedef struct s_texture
{
	char	*path;
	char	**lines;
	int		width;
	int		height;
	int		nb_colors;
	int		key_size;
	int		*color;
	int		*key;
	int		*data;
}	t_texture;

typedef struct s_textures
{
	t_texture	*no;
	t_texture	*so;
	t_texture	*ea;
	t_texture	*we;
}	t_textures;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	angle;
	float	fov;
	int		rotate;
	int		x_way;
	int		y_way;
	t_data	*cub;
}	t_player;

typedef struct s_ray
{
	double	ray_ngl;
	double	distance;
	bool	horizontal;
	float	x_step;
	float	y_step;
	float	h_x;
	float	h_y;
	float	v_x;
	float	v_y;
	float	x;
	float	y;
	int		adjust;
	double	wall_h;
	t_data	*cub;
}	t_ray;

typedef struct s_game
{
	void		*mlx_img;
	void		*mlx_p;
	void		*mlx_win;
	t_ray		*ray;
	t_player	*player;
	t_data		*cub;
}	t_game;

typedef struct s_pathf
{
	int	player_x;
	int	player_y;
	int	**visited;
	int	can_escape;
	int	i;
	int	j;
}	t_pathf;

typedef struct s_pathf2
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_pathf2;

typedef struct s_data
{
	t_map		*map;
	char		*gd_args;
	t_textures	*textures;
	t_color		*c;
	t_color		*f;
	t_game		*game;
	int			ori;
}	t_data;

#endif