#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y)
{
		int i = 0;
		int j;
		char *dst;

		while (i < x)
		{
			j = 0;
			while (j < y)
			{
				dst = game->mlx_img + (j++ * 1000 + i * (16 / 8));
				*(unsigned int*)dst = 0xB5B5B5FF;
			}
			i++;
		}
}

int key_management(t_game *game)
{
	ft_putstr_fd("dddd", 1);
	return 0;
}

int game_loop(t_game *game)
{
	t_game temp;

	temp = *game;

	game->mlx_img = mlx_new_image(game->mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT);
	//my_mlx_pixel_put(game, 100, 100);
	mlx_put_image_to_window(game->mlx_p, game->mlx_win ,game->mlx_img, 0, 0);
	return 0;
}

int exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_p, game->mlx_win);
	return 0;
}

int launcher(void)
{
	t_game game;

	game.mlx_p = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_p, SCREEN_WIDTH, SCREEN_HEIGHT, WIN_NAME);
	mlx_loop_hook(game.mlx_p, &game_loop, &game);
	mlx_hook(game.mlx_win, 17, 0, &exit_game, &game);
	mlx_key_hook(game.mlx_win, &key_management, &game);
	mlx_loop(game.mlx_p);
	return (0);
}