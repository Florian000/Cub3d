#include "../../include/cub3d.h"

int init_map(t_data *data)
{
    if (!data || !data->map)
        return (INVALID);

    data->map->height = 0;
    data->map->length = 0;
    data->map->brut_map = NULL;
    data->map->real_map = NULL;
    return (VALID);
}

int init_c(t_data *data)
{
    if (!data)
        return (INVALID);
    t_color *c = malloc(sizeof(t_color));
    if (!c)
        return (INVALID);
    c->B = -1;
    c->G = -1;
    c->R = -1;
    data->C = c;
    return (VALID);
}

int init_f(t_data *data)
{
    if (!data)
        return (INVALID);

    t_color *c = malloc(sizeof(t_color));
    if (!c)
        return (INVALID);
    c->B = -1;
    c->G = -1;
    c->R = -1;
    data->F = c;
    return (VALID);
}

int init_texture(t_data *data)
{
    if (!data)
        return (INVALID);

    t_textures *t = malloc(sizeof(t_textures));
    if (!t)
        return (INVALID);
    t->EA = NULL;
    t->NO = NULL;
    t->SO = NULL;
    t->WE = NULL;
    data->textures = t;
    return (VALID);
}

int init_data(void)
{
    t_data *data = get_data();
    if (!data)
        return (INVALID);
    ft_bzero(data, sizeof(t_data));
    data->map = malloc(sizeof(t_map));
    if (!data->map)
        return (INVALID);
    if (init_map(data) == INVALID ||
        init_c(data) == INVALID ||
        init_f(data) == INVALID ||
        init_texture(data) == INVALID)
    {
        free_data(data);
        return (INVALID);
    }
    data->gd_args = NULL;

    return (VALID);
}
