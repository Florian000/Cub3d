#include "../../include/cub3d.h"

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
