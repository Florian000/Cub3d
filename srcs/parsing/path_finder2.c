/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:45 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/14 17:33:34 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	validate_map3(int *i, int **visited, t_map *map)
{
	while (*i < map->height)
	{
		visited[*i] = (int *)calloc(map->length, sizeof(int));
		if (!visited[*i])
		{
			while ((*i)-- > 0)
				free(visited[*i]);
			free(visited);
			exit_game("Memory allocation error.");
		}
		*i = *i + 1;
	}
}

int	validate_map(t_map *map)
{
	t_pathf	f;

	if (!map || map->real_map == NULL)
		return (INVALID);
	f.player_x = -1;
	f.player_y = -1;
	f.i = 0;
	validate_map2(&f.i, &f.j, &f.player_x, &f.player_y);
	if (f.player_x == -1 || f.player_y == -1)
		return (exit_game("Player not found on the map."));
	f.visited = (int **)malloc(map->height * sizeof(int *));
	if (!f.visited)
		return (exit_game("Memory allocation error."));
	f.i = 0;
	validate_map3(&f.i, f.visited, map);
	f.i = f.player_y;
	f.j = f.player_x;
	f.can_escape = flood_fill_check(map->real_map, map->height, map->length, f);
	f.i = 0;
	while (f.i < map->height)
		free(f.visited[f.i++]);
	free(f.visited);
	if (f.can_escape == INVALID)
		return (exit_game("The map allows escape."));
	return (VALID);
}
