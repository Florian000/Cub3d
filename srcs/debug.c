#include "../include/cub3d.h"

void    print_brut_map(void)
{
    t_data  *data;
    int     i;

    data = get_data();
    i = 0;
    while (data->brut_map[i])
        printf("%s", data->brut_map[i++]);
}