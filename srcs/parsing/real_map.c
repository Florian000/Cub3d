#include "../../include/cub3d.h"

//prepares the map of int easyer to use (does not check hight or length)
int init_real_map(void)
{
    t_map   *map;
    int     i;

    i = 0;
    map = get_data()->map;
    map->real_map = malloc(sizeof(int *) * map->height);
    if (!map->real_map)
        return (INVALID);
    while (i < map->height)
    {
        map->real_map[i] = malloc(sizeof(int) * map->length);
        if (!map->real_map[i])
        {
            while (i-- > 0)
                free(map->real_map[i]);
            free(map->real_map);
            return (INVALID);
        }
        i++;
    }
    return (VALID);
}

int fill_real_map(void)
{
    t_map   *map;
    int     i;
    int     j;

    map = get_data()->map;
    if (!map || !map->brut_map || !map->real_map)
        return (INVALID);
    i = 0;
    while (i < map->height)
    {
        j = 0;
        if (!map->brut_map[i])
        {
            while (j < map->length)
                map->real_map[i][j++] = 0;
            i++;
            continue;
        }
        while (j < map->length)
        {
            if (j < ft_strlen(map->brut_map[i]) && map->brut_map[i][j])
            {
                if (ft_isspace(map->brut_map[i][j]) == 1)
                    map->real_map[i][j] = 0;
                else if ((map->brut_map[i][j]))
                    map->real_map[i][j] = map->brut_map[i][j] - '0';
                else
                    map->real_map[i][j] = 0;
            }
            else
                map->real_map[i][j] = 0;
            j++;
        }
        i++;
    }
    return (VALID);
}
