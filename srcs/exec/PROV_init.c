#include "../../include/cub3d.h"

void init_argumet(t_data *cub) // init the data structure
{
	cub->map->brut_map = calloc(10, sizeof(char *));
	cub->map->brut_map[0] = strdup("1111111111111111111111111");
	cub->map->brut_map[1] = strdup("2000000000000000000000004");
	cub->map->brut_map[2] = strdup("2000000111111110000000004");
	cub->map->brut_map[3] = strdup("2000000100000000000000004");
	cub->map->brut_map[4] = strdup("2000000100000000000000004");
	cub->map->brut_map[5] = strdup("2000000100000000000000004");
	cub->map->brut_map[6] = strdup("2000000000000000000000004");
	cub->map->brut_map[7] = strdup("2000000000000000000000004");
	cub->map->brut_map[8] = strdup("3333333333333333333333333");
	cub->map->brut_map[9] = NULL;
	cub->map->pos_x= 2;
	cub->map->pos_y = 2;
	cub->map->length = 25;
	cub->map->hight= 9;
}

void init_player(t_data *cub)
{
	cub->game->play = ft_calloc(1, sizeof(t_player));

	cub->game->play->pos_x = cub->map->pos_x * TILE_SIZE + TILE_SIZE / 2;
	cub->game->play->pos_y = cub->map->pos_y * TILE_SIZE + TILE_SIZE / 2;
	cub->game->play->fov = FOV;
	cub->game->play->angle = M_PI_2;
}

void init_game(t_data *cub)
{
	cub->game = calloc(1, sizeof(t_game));
	cub->game->ray = calloc(1, sizeof(t_ray));
	init_argumet(cub);
	init_player(cub);
}
