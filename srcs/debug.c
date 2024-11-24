#include "../include/cub3d.h"

void    print_brut_map(void)
{
    t_data  *data;
    int     i;

    data = get_data();
    i = 0;
    printf("hight : %d\n", data->map->hight);
    printf("length : %d\n", data->map->length);
    while (data->map->brut_map[i])
        printf("%s", data->map->brut_map[i++]);
}

void    print_real_map(void)
{
    t_map *map;
    int     i;
    int     j;

    i = 0;
    map = get_data()->map;
    while (i < map->hight)
    {
        j = 0;
        while (j < map->length)
        {
            printf(" %3d ", map->real_map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}