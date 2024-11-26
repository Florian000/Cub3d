#include "../../include/cub3d.h"

int free_map(t_data *data)
{
    int i;

    if (data->map->real_map)
    {
        i = 0;
        while (i < data->map->hight)
        {
            free(data->map->real_map[i]);
            i++;
        }
        free(data->map->real_map);
    }
    return (INVALID);
}

int free_textures(t_data *data)
{
    t_textures *t;

    t = data->textures;
    if (t)
    {
        if (t->EA)
            free(t->EA);
        if (t->NO)
            free(t->NO);
        if (t->SO)
            free(t->SO);
        if (t->WE)
            free(t->WE);
        free(t);
    }
    return (VALID);
}

//empties the data structure
int free_data(t_data *data)
{
    if (!data)
        return (INVALID);
    free_map(data);
    if (data->map->brut_map)
        ft_free(VALID, "s", data->map->brut_map);
    if (data->map)
        free(data->map);
    if (data->gd_args)
        free(data->gd_args);
    free_textures(data);
    free(data->C);
    free(data->F);
    return (VALID);
}
