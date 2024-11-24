#include "../../include/cub3d.h"

//initializes the data strure
int  init_data(void)
{
    t_data *data;

    data = get_data();
    ft_bzero(data, sizeof(t_data));
    data->map = malloc(sizeof(t_map));
    data->gd_args = NULL;
    return (VALID);
}

int init_map(t_data *data)
{
    t_map *map;

    map = data->map;
    map->hight = 0;
    map->length = 0;
    map->brut_map = NULL;
    return (VALID);
}