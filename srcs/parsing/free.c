#include "../../include/cub3d.h"

int free_map(t_data *data)
{
    if (data->map->real_map)
    {
        if (data->map->hight > 0 && data->map->length > 0)
            free(data->map->real_map); // incomplete !! do nto use
    }
    return (INVALID);
}

//empties the data structure
int free_data(t_data *data)
{
    if (!data)
        return (INVALID);
    if (data->map->brut_map)
        ft_free(VALID, "s", data->map->brut_map);
    if (data->map)
        free(data->map);
    if (data->gd_args)
        free(data->gd_args);

    return (VALID);
}
