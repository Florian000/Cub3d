/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:45 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 19:04:47 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Check if the current position is within bounds
int is_within_bounds(int x, int y, int width, int height) 
{
    return (x >= 0 && x < width && y >= 0 && y < height);
}

//flood check from the player/location
int flood_fill_check(int **map, int height, int length, int x, int y, int **visited)
{
    int up;
    int down;
    int left;
    int right;

    if (!is_within_bounds(x, y, length, height))
        return (INVALID);
    if (visited[y][x])
        return (VALID);
    if (map[y][x] == 1 || map[y][x] == -1)
        return (VALID);
    if ((x == 0 || x == length - 1 || y == 0 || y == height - 1) && map[y][x] == 0)
        return (INVALID);
    visited[y][x] = 1;
    up = flood_fill_check(map, height, length, x, y - 1, visited);
    down = flood_fill_check(map, height, length, x, y + 1, visited);
    left = flood_fill_check(map, height, length, x - 1, y, visited);
    right = flood_fill_check(map, height, length, x + 1, y, visited);
    if (up == INVALID || down == INVALID || left == INVALID || right == INVALID)
        return (INVALID);
    return (VALID);
}

//flood the map to check player is cosed
int validate_map(t_map *map) 
{
    int player_x = -1;
    int player_y = -1;
    int **visited;
    int can_escape;
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->length)
        {
            if (map->real_map[i][j] > 10) // multiple players ?
            {
                map->pos_x = j;
                map->pos_y = i;
                player_x = j;
                player_y = i;
                get_data()->ori = map->real_map[i][j];
                break;
            }
            j++;
        }
        if (player_x != -1 && player_y != -1)
            break;
        i++;
    }
    if (player_x == -1 || player_y == -1)
        return err("No player in map");
    visited = (int **)malloc(map->height * sizeof(int *));
    i = 0;
    while (i < map->height)
        visited[i++] = (int *)calloc(map->length, sizeof(int));
    can_escape = flood_fill_check(map->real_map, map->height, map->length, player_x, player_y, visited);
    i = 0;
    while (i < map->height)
        free(visited[i++]);
    free(visited);
    if (can_escape == INVALID)
       return err("Open map");
    return VALID;
}
