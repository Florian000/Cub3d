#include "../../include/cub3d.h"

//extention of init_data
int init_map(t_data *data)
{
    t_map *map;

    map = data->map;
    map->hight = 0;
    map->length = 0;
    map->brut_map = NULL;
    map->real_map = NULL;
    return (VALID);
}

int init_c(t_data *data)
{
    t_color *c;

    c = malloc(sizeof(t_color));
    c->B = -1;
    c->G = -1;
    c->R = -1;
    data->C = c;
    return (VALID);
}

int init_f(t_data *data)
{
    t_color *c;

    c = malloc(sizeof(t_color));
    c->B = -1;
    c->G = -1;
    c->R = -1;
    data->F = c;
    return (VALID);
}

int init_texture(t_data *data)
{
    t_textures *t;

    t = malloc(sizeof(t_textures));
    t->EA = NULL;
    t->NO = NULL;
    t->SO = NULL;
    t->WE = NULL;
    data->textures = t;
    return (VALID);
}

int  init_data(void)
{
    t_data *data;

    data = get_data();
    ft_bzero(data, sizeof(t_data));
    data->map = malloc(sizeof(t_map));
    init_map(data);
    data->gd_args = NULL;
    init_c(data);
    init_f(data);
    init_texture(data);
    return (VALID);
}