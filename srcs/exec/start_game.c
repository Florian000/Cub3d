/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/07 13:36:41 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	game_loop(t_game *game)
{
	hook(game);
	return (EXIT_SUCCESS);
}

int	launcher(t_game *g)
{
	g->mlx_p = mlx_init();
	g->mlx_img = mlx_new_image(g->mlx_p, WIDTH, HEIGHT);
	g->mlx_win = mlx_new_window(g->mlx_p, WIDTH, HEIGHT, WIN_NAME);
	cast_rays(g->ray, g->player);
	mlx_put_image_to_window(g->mlx_p, g->mlx_win, g->mlx_img, 0, 0);
	mlx_hook(g->mlx_win, KeyPress, KeyPressMask, &key_press, g->player);
	mlx_hook(g->mlx_win, KeyRelease, KeyReleaseMask, &key_release, g->player);
	mlx_hook(g->mlx_win, 33, 1L << 17, exit_game, g);
	mlx_loop_hook(g->mlx_p, &game_loop, g);
	mlx_loop(g->mlx_p);
	exit_game(g);
	return (EXIT_SUCCESS);
}
