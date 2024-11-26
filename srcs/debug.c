#include "../include/cub3d.h"

void    print_brut_map(void)
{
    t_data  *data;
    int     i;

    data = get_data();
    i = 0;
    printf("hight : %d\n", data->map->hight);
    printf("length : %d\n\n", data->map->length);

    printf("F : \n");
    printf("R : %d\n", data->F->R);
    printf("G : %d\n", data->F->G);
    printf("B : %d\n\n", data->F->B);

    printf("C : \n");
    printf("R : %d\n", data->C->R);
    printf("G : %d\n", data->C->G);
    printf("B : %d\n\n", data->C->B);

    printf("Textures : \n");
    printf("NO : %s\n", data->textures->NO);
    printf("SO : %s\n", data->textures->SO);
    printf("EA : %s\n", data->textures->EA);
    printf("WE : %s\n\n", data->textures->WE);

    while (data->map->brut_map[i])
        printf("%s\n", data->map->brut_map[i++]);
    printf("\n\n");
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