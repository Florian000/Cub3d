/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:45 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/13 20:23:04 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_within_bounds(int x, int y, int width, int height)
{
	return (x >= 0 && x < width && y >= 0 && y < height);
}

int	flood_fill_check(int **map, int height, int length, t_pathf f)
{
	t_pathf2	f2;

	if (!is_within_bounds(f.j, f.i, length, height))
		return (INVALID);
	if (f.visited[f.i][f.j])
		return (VALID);
	if (map[f.i][f.j] == 1 || map[f.i][f.j] == -1)
		return (VALID);
	if ((f.i == 0 || f.j == 0 || f.i == height - 1
			|| f.j == length - 1) && map[f.i][f.j] == 0)
		return (INVALID);
	f.visited[f.i][f.j] = 1;
	f.i -= 1;
	f2.up = flood_fill_check(map, height, length, f);
	f.i += 2;
	f2.down = flood_fill_check(map, height, length, f);
	f.i -= 1;
	f.j -= 1;
	f2.left = flood_fill_check(map, height, length, f);
	f.j += 2;
	f2.right = flood_fill_check(map, height, length, f);
	f.j -= 1;
	if (f2.up == 1 || f2.down == 1 || f2.left == 1 || f2.right == 1)
		return (INVALID);
	return (VALID);
}

int	check_nb_player(t_data *data)
{
	int		i;
	int		j;
	char	**m;
	int		res;

	i = 0;
	res = 0;
	m = data->map->brut_map;
	while (m && m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'N' || m[i][j] == 'S'
				|| m[i][j] == 'E' || m[i][j] == 'W')
				res++;
			j++;
		}
		i++;
	}
	if (res != 1)
		return (INVALID);
	return (VALID);
}

void	validate_map2(int *i, int *j, int *player_x, int *player_y)
{
	t_map	*map;

	map = get_data()->map;
	while (*i < map->height)
	{
		*j = 0;
		while (*j < map->length)
		{
			if (map->real_map[*i][*j] > 10)
			{
				map->pos_x = *j;
				map->pos_y = *i;
				*player_x = *j;
				*player_y = *i;
				get_data()->ori = map->real_map[*i][*j];
				break ;
			}
			*j = *j + 1;
		}
		if (*player_x != -1 && *player_y != -1)
			break ;
		*i = *i + 1;
	}
}
