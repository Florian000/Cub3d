/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:03:50 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/14 18:12:57 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_free2(int res, char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (res);
}

int	free_map(t_map *map)
{
	int	i;

	if (!map)
		return (VALID);
	if (map->brut_map)
	{
		i = 0;
		while (map->brut_map[i])
			free(map->brut_map[i++]);
		free(map->brut_map);
	}
	if (map->real_map)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->real_map[i])
				free(map->real_map[i]);
			i++;
		}
		free(map->real_map);
	}
	free(map);
	return (VALID);
}

void	null_loop(t_data *data)
{
	data->c = NULL;
	data->f = NULL;
	data->game = NULL;
	data->gd_args = NULL;
	data->map = NULL;
	data->textures = NULL;
}

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->c)
		free(data->c);
	if (data->f)
		free(data->f);
	if (data->textures)
	{
		free_texture(data->textures->ea);
		free_texture(data->textures->no);
		free_texture(data->textures->so);
		free_texture(data->textures->we);
		free(data->textures);
	}
	if (data->game)
	{
		free_mlx(data->game);
		free(data->game->player);
		free(data->game->ray);
		free(data->game);
	}
	if (data->map)
		free_map(data->map);
	null_loop(data);
	data = NULL;
}
