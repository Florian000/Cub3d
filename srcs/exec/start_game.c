#include "../../include/cub3d.h"

int game_loop(t_data *cub)
{
	hook(cub);
	return 0;
}

int launcher(t_game *game)
{
	game->mlx_p = mlx_init();
	game->mlx_img = mlx_new_image(game->mlx_p, WIDTH, HEIGHT);
	game->mlx_win = mlx_new_window(game->mlx_p, WIDTH, HEIGHT, WIN_NAME);
	cast_rays(game->ray, game->player);
	mlx_put_image_to_window(game->mlx_p, game->mlx_win ,game->mlx_img, 0, 0);
	mlx_hook(game->mlx_win, KeyPress, KeyPressMask, &key_press, game->player);
	mlx_hook(game->mlx_win, KeyRelease, KeyReleaseMask, &key_release, game->player);
	mlx_loop_hook(game->mlx_p, &game_loop, game);
	mlx_loop(game->mlx_p);
	exit_game(game);
	return (0);
}