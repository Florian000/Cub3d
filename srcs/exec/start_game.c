/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/13 20:18:24 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_player(t_data *cub)
{
	cub->game->player->pos_x = cub->map->pos_x * TILE_SIZE + TILE_SIZE / 2;
	cub->game->player->pos_y = cub->map->pos_y * TILE_SIZE + TILE_SIZE / 2;
	cub->game->player->fov = FOV;
	if (get_data()->ori == 30)
		cub->game->player->angle = M_PI_2 * 3;
	else if (get_data()->ori == 35)
		cub->game->player->angle = M_PI_2;
	else if (get_data()->ori == 39)
		cub->game->player->angle = 0;
	else
		cub->game->player->angle = M_PI;
	cub->game->player->cub = cub;
}

int	init_game(t_data *cub)
{
	init_player(cub);
	if (init_text(cub->textures->ea) == INVALID)
		return (INVALID);
	if (init_text(cub->textures->no) == INVALID)
		return (INVALID);
	if (init_text(cub->textures->we) == INVALID)
		return (INVALID);
	if (init_text(cub->textures->so) == INVALID)
		return (INVALID);
	cub->f->color = get_rgb(cub->f->r, cub->f->g, cub->f->b);
	cub->c->color = get_rgb(cub->c->r, cub->c->g, cub->c->b);
	return (VALID);
}

int	game_loop(t_game *game)
{
	hook(game);
	return (EXIT_SUCCESS);
}

int	close_win(t_game *g)
{
	exit_game(g, NULL);
	return (EXIT_FAILURE);
}

int	launcher(t_game *g)
{
	g->mlx_p = mlx_init();
	if (g->mlx_p == NULL)
		exit_game(g, "mlx init error");
	g->mlx_img = mlx_new_image(g->mlx_p, WIDTH, HEIGHT);
	if (g->mlx_img == NULL)
		exit_game(g, "mlx new image error");
	g->mlx_win = mlx_new_window(g->mlx_p, WIDTH, HEIGHT, WIN_NAME);
	if (g->mlx_win == NULL)
		exit_game(g, "mlx new window error");
	cast_rays(g->ray, g->player);
	mlx_put_image_to_window(g->mlx_p, g->mlx_win, g->mlx_img, 0, 0);
	mlx_hook(g->mlx_win, KeyPress, KeyPressMask, &key_press, g->player);
	mlx_hook(g->mlx_win, KeyRelease, KeyReleaseMask, &key_release, g->player);
	mlx_hook(g->mlx_win, 33, 1L << 17, close_win, g);
	mlx_loop_hook(g->mlx_p, &game_loop, g);
	mlx_loop(g->mlx_p);
	exit_game(g, NULL);
	return (EXIT_SUCCESS);
}
