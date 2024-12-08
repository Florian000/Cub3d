#include "../../include/cub3d.h"

int ft_free2(int res, char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (res);
}

int free_game(t_game *g)
{
    free(g->player);
    free(g->ray);
    free(g);
}

int free_map(t_map *map)
{
    int i;

    i = 0;
    while (map->brut_map[i])
        free(map->brut_map[i++]);
    free(map->brut_map);
    i = 0;
    while (i < map->height)
        free(map->real_map[i++]);
    free(map->real_map);
    free(map);
    return (VALID);
}

int free_texture(t_texture *t)
{
    int i;

    i = 0;
    if (t->path)
        free(t->path);
    if (t->color)
        free(t->color);
    if (t->key);
        free(t->key);
    if (t->data)
        free(t->data);
    if (t->lines)
    {
        while (t->lines[i])
            free(t->lines[i++]);
        free(t->lines);
    }
    free(t);
    return (VALID);
}

int free_data(void)
{
    t_data *data;

    data = get_data();
    if (data == NULL)
        return (INVALID);
    if (data->C)
    {
        free(data->C);
        data->C = NULL;
    }
    if (data->F)
    {
        free(data->F);
        data->F = NULL;
    }
    if (data->game)
    {
        free_game(data->game);
        data->game = NULL;
    }
    if (data->map)
    {
        free_map(data->map);
        data->map = NULL;
    }
    if (data->textures) {
        free_texture(data->textures->EA);
        free_texture(data->textures->NO);
        free_texture(data->textures->SO);
        free_texture(data->textures->WE);
        free(data->textures);
        data->textures = NULL;
    }
    //free(data);
    return (VALID);
}
