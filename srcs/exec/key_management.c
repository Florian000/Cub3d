/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/07 14:14:36 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_release(int key, t_player *player)
{
	if (key == XK_D || key == XK_d)
		player->x_way = 0;
	else if (key == XK_A || key == XK_a)
		player->x_way = 0;
	else if (key == XK_S || key == XK_s)
		player->y_way = 0;
	else if (key == XK_W || key == XK_w)
		player->y_way = 0;
	else if (key == XK_Left)
		player->rotate = 0;
	else if (key == XK_Right)
		player->rotate = 0;
	return (EXIT_SUCCESS);
}

int	key_press(int key, t_player *player)
{
	if (key == XK_Escape)
		exit_game(player->cub->game);
	else if (key == XK_A || key == XK_a)
		player->x_way = -1;
	else if (key == XK_D || key == XK_d)
		player->x_way = 1;
	else if (key == XK_S || key == XK_s)
		player->y_way = -1;
	else if (key == XK_W || key == XK_w)
		player->y_way = 1;
	else if (key == XK_Left)
		player->rotate = -1;
	else if (key == XK_Right)
		player->rotate = 1;
	return (EXIT_SUCCESS);
}

void	check_hits(t_player *player, double x, double y, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = floor((player->pos_x + x) / TILE_SIZE);
	new_y = floor((player->pos_y + y) / TILE_SIZE);
	if (map->brut_map[new_y][new_x] == '0')
	{
		printf(" - ok - ");
		player->pos_x += x;
		player->pos_y += y;
		printf("back x = %f, y = %f\n", player->pos_x, player->pos_y );
	}
	else
		printf("back x = %f, y = %f\n", player->pos_x + x, player->pos_y + y);
}

void	move_player(t_player *player)
{
	double	move_x;
	double	move_y;

	if (player->x_way == 1)
	{
		move_x = -sin(player->angle) * PLAYER_SPEED;
		move_y = cos(player->angle) * PLAYER_SPEED;
	}
	if (player->x_way == -1)
	{
		move_x = sin(player->angle) * PLAYER_SPEED;
		move_y = -cos(player->angle) * PLAYER_SPEED;
	}
	if (player->y_way == 1)
	{
		move_x = cos(player->angle) * PLAYER_SPEED;
		move_y = sin(player->angle) * PLAYER_SPEED;
		printf("back x = %f, y = %f", move_x, move_y);
	}
	if (player->y_way == -1)
	{
		move_x = -cos(player->angle) * PLAYER_SPEED;
		move_y = -sin(player->angle) * PLAYER_SPEED;
		printf("front x = %f, y = %f", move_x, move_y);
	}
	check_hits(player, move_x, move_y, player->cub->map);
}

void	hook(t_game *g)
{
	if (g->player->rotate == 1)
		g->player->angle = nor_angle(g->player->angle + ROTATION_SPEED);
	if (g->player->rotate == -1)
		g->player->angle = nor_angle(g->player->angle - ROTATION_SPEED);
	if (g->player->y_way != 0 || g->player->x_way != 0)
		move_player(g->player);
	if (g->player->y_way != 0 || g->player->rotate != 0
		|| g->player->x_way != 0)
	{
		cast_rays(g->ray, g->player);
		mlx_put_image_to_window(g->mlx_p, g->mlx_win, g->mlx_img, 0, 0);
	}
}
