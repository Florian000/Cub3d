#include "../../include/cub3d.h"

int game_loop(t_data *cub)
{
	hook(cub);
	return 0;
}

int launcher(t_data *cub)
{
	init_game(cub);
	cub->game->mlx_p = mlx_init();
	cub->game->mlx_img = mlx_new_image(cub->game->mlx_p, WIDTH, HEIGHT);
	cub->game->mlx_win = mlx_new_window(cub->game->mlx_p, WIDTH, HEIGHT, WIN_NAME);
	cast_rays(cub);
	mlx_put_image_to_window(cub->game->mlx_p, cub->game->mlx_win ,cub->game->mlx_img, 0, 0);
	mlx_hook(cub->game->mlx_win, KeyPress, KeyPressMask, &key_press, cub);
	mlx_hook(cub->game->mlx_win, KeyRelease, KeyReleaseMask, &key_release, cub);
	mlx_loop_hook(cub->game->mlx_p, &game_loop, cub);
	mlx_loop(cub->game->mlx_p);
	exit_game(cub->game);
	return (0);
}