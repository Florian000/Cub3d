#include "../../include/cub3d.h"

//extention of init_data
int init_map(t_data *data)
{
    t_map *map;

    map = data->map;
    map->hight = 0;
    map->length = 0;
    map->brut_map = NULL;
    return (VALID);
}

//initializes the data strure
int  init_data(void)
{
    t_data *data;

    data = get_data();
    ft_bzero(data, sizeof(t_data));
    data->map = malloc(sizeof(t_map));
    init_map(data);
    data->gd_args = NULL;
    return (VALID);
}