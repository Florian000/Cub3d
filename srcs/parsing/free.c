#include "../../include/cub3d.h"

int free_data(t_data *data)
{
    if (!data)
        return (INVALID);
    if (data->brut_map)
        free(data->brut_map);

    if (data->gd_args)
        free(data->gd_args);

    return (VALID);
}
