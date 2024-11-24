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