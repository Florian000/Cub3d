#include "../../include/cub3d.h"

t_player *end_init_player(void)
{
    t_player *player;

    player = malloc(sizeof(t_player));
    if (!player)
        return (NULL);
    player->angle = 0;
    player->cub = get_data();
    player->fov = 0;
    player->pos_x = 0;
    player->pos_y = 0;
    player->rotate = 0;
    player->x_way = 0;
    player->y_way = 0;
    return (player);
}

t_ray *end_init_ray(void)
{
    t_ray *ray;

    ray = malloc(sizeof(t_ray));
    if (!ray)
        return (NULL);
    ray->cub = get_data();
    ray->adjust = 0;
    ray->distance = 0;
    ray->h_x = 0;
    ray->h_y = 0;
    ray->horizontal = 0;
    ray->ray_ngl = 0;
    ray->v_x = 0;
    ray->v_y = 0;
    ray->x = 0;
    ray->x_step = 0;
    ray->y = 0;
    ray->y_step = 0;
    return (ray);
}

int end_init_game(t_data *data)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
        return (INVALID);
    game->ray = end_init_ray();
    if (!game->ray)
    {
        free(game);
        return (INVALID);
    }
    game->player = end_init_player();
    if (!game->player)
    {
        free(game->ray);
        free(game);
        return (INVALID);
    }
    game->cub = data;
    game->mlx_img = NULL;
    game->mlx_p = NULL;
    game->mlx_win = NULL;
    data->game = game;
    return (VALID);
}
