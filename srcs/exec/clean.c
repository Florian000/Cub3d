/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/08 11:24:45 by fgranger         ###   ########.fr       */
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

void clean_texture(t_texture *texture)
{
	int i;

	i = 0;
	if (texture->data)
		free(texture->data);
	if (texture->color)
		free(texture->color);
	if (texture->path)
		free(texture->path);
	if (texture->key)
		free(texture->key);
	if (texture->lines)
	{
		while (texture->lines[i])
				free(texture->lines[i++]);
		free(texture->lines);
	}
	free(texture);
}

void	clean_textures(t_textures *textures)
{
	if (textures->EA)
		clean_texture(textures->EA);
	if (textures->WE)
		clean_texture(textures->WE);
	if (textures->NO)
		clean_texture(textures->NO);
	if (textures->SO)
		clean_texture(textures->SO);
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
		//clean_texture(cub->textures);
	if (cub->game)
		clean_game(cub->game);
}
