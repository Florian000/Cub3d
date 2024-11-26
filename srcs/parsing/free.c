#include "../../include/cub3d.h"

int free_map(t_data *data)
{
    int i;

    if (data->map && data->map->real_map)
    {
        i = 0;
        while (i < data->map->hight)
        {
            if (data->map->real_map[i])
                free(data->map->real_map[i]);
            i++;
        }
        free(data->map->real_map);
    }
    return (INVALID);
}

int free_textures(t_data *data)
{
    if (data && data->textures)
    {
        t_textures *t = data->textures;

        if (t->EA)
        {
            free(t->EA);
            t->EA = NULL;
        }
        if (t->NO)
        {
            free(t->NO);
            t->NO = NULL;
        }
        if (t->SO)
        {
            free(t->SO);
            t->SO = NULL;
        }
        if (t->WE)
        {
            free(t->WE);
            t->WE = NULL;
        }
        free(t);
        data->textures = NULL;
    }
    return (VALID);
}

int free_data(t_data *data)
{
    if (!data)
        return (INVALID);
    if (data->map)
    {
        free_map(data);
        if (data->map->brut_map)
            ft_free(VALID, "s", data->map->brut_map);
        free(data->map);
    }
    if (data->gd_args)
        free(data->gd_args);
    if (data->C)
        free(data->C);
    if (data->F)
        free(data->F);
    if (data->textures)
        free_textures(data);
    return (VALID);
}
