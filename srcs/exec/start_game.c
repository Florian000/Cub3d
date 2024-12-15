/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/15 12:23:27 by fgranger         ###   ########.fr       */
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

void	init_text(t_texture *t, t_game *g)
{
	int	*x;

	t->img = mlx_xpm_file_to_image(g->mlx_p, t->path, &t->width, &t->height);
	if (!t->img)
		exit_game("Failed to read XPM");
	x = (int *)mlx_get_data_addr(t->img, &t->bpp, &t->size_line, &t->endian);
	if (!x)
		exit_game("Failed mlx get data");
	t->addr_img = x;
}

void	init_game(t_game *g, t_textures *t)
{
	init_player(g->cub);
	t->ea->cub = g->cub;
	t->no->cub = g->cub;
	t->so->cub = g->cub;
	t->we->cub = g->cub;
	init_text(t->ea, g);
	init_text(t->no, g);
	init_text(t->so, g);
	init_text(t->we, g);
	g->cub->f->color = get_rgb(g->cub->f->r, g->cub->f->g, g->cub->f->b);
	g->cub->c->color = get_rgb(g->cub->c->r, g->cub->c->g, g->cub->c->b);
}

int	game_loop(t_game *game)
{
	hook(game);
	return (EXIT_SUCCESS);
}

int	launcher(t_game *g)
{
	g->mlx_p = mlx_init();
	if (g->mlx_p == NULL)
		exit_game("mlx init error");
	init_game(get_data()->game, get_data()->textures);
	welcome_print();
	g->mlx_img = mlx_new_image(g->mlx_p, WIDTH, HEIGHT);
	if (g->mlx_img == NULL)
		exit_game("mlx new image error");
	g->mlx_win = mlx_new_window(g->mlx_p, WIDTH, HEIGHT, WIN_NAME);
	if (g->mlx_win == NULL)
		exit_game("mlx new window error");
	cast_rays(g->ray, g->player);
	mlx_put_image_to_window(g->mlx_p, g->mlx_win, g->mlx_img, 0, 0);
	mlx_hook(g->mlx_win, KeyPress, KeyPressMask, &key_press, g->player);
	mlx_hook(g->mlx_win, KeyRelease, KeyReleaseMask, &key_release, g->player);
	mlx_hook(g->mlx_win, 33, 1L << 17, exit_game, NULL);
	mlx_loop_hook(g->mlx_p, &game_loop, g);
	mlx_loop(g->mlx_p);
	exit_game(NULL);
	return (EXIT_SUCCESS);
}
