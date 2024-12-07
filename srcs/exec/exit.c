/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/07 13:48:20 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	clean_map(t_map *map)
{	
	int	i;

	i = 0;
	if (map->brut_map)
	{
		while (map->brut_map[i])
			free(map->brut_map[i++]);
		free(map->brut_map);
	}
	//add free realmap
	free(map);
}

void	clean_texture(t_textures *textures)
{
	//add subcleaning when used
	free(textures);
}

void	clean_game(t_game *game)
{
	if (game->mlx_img)
		mlx_destroy_image(game->mlx_p, game->mlx_img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_p, game->mlx_win);
	if (game->mlx_p)
	{
		mlx_destroy_display(game->mlx_p);
		free(game->mlx_p);
	}
	if (game->ray)
		free(game->ray);
	if (game->player)
		free(game->player);
	free(game);
}

void	clean_all(t_data *cub)
{
	if (cub->map)
		clean_map(cub->map);
	if (cub->gd_args)
		free(cub->gd_args);
	if (cub->C)
		free(cub->C);
	if (cub->F)
		free(cub->F);
	if (cub->textures)
		clean_texture(cub->textures);
	if (cub->game)
		clean_game(cub->game);
}

int	exit_game(t_game *game)
{
	clean_all(game->cub);
	exit(0);
}
