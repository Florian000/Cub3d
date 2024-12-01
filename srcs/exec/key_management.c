#include "../../include/cub3d.h"

void	key_release(int key, t_data *cub)
{
	ft_putstr_fd("released\n", 1);
	if (key == XK_D || key == XK_d)
		cub->game->play->x_way = 0;
	else if (key == XK_A || key == XK_a)
		cub->game->play->x_way = 0;
	else if (key == XK_S || key == XK_s)
		cub->game->play->y_way = 0;
	else if (key == XK_W || key == XK_w)
		cub->game->play->y_way = 0;
	else if (key == XK_Left)
		cub->game->play->rotate = 0;
	else if (key == XK_Right)
		cub->game->play->rotate = 0;
}

void key_press(int key, t_data *cub)
{
	ft_putstr_fd("pressed\n", 1);
	if (key == XK_Escape)
		exit(0);
	else if (key == XK_A || key == XK_a)
		cub->game->play->x_way = -1;
	else if (key == XK_D || key == XK_d)
		cub->game->play->x_way = 1;
	else if (key == XK_S || key == XK_s)
		cub->game->play->y_way = -1;
	else if (key == XK_W || key == XK_w)
		cub->game->play->y_way = 1;
	else if (key == XK_Left)
		cub->game->play->rotate = -1;
	else if (key == XK_Right)
		cub->game->play->rotate = 1;
}

void	hook(t_data *cub)	// hook the player
{
	if (cub->game->play->rotate == 1)
		cub->game->play->angle += ROTATION_SPEED;
	if (cub->game->play->rotate == -1)
		cub->game->play->angle -= ROTATION_SPEED;
	if (cub->game->play->x_way == 1)
		cub->game->play->pos_x += PLAYER_SPEED;
	if (cub->game->play->x_way == -1)
		cub->game->play->pos_x -= PLAYER_SPEED;
	if (cub->game->play->y_way == 1)
		cub->game->play->pos_y += PLAYER_SPEED;
	if (cub->game->play->y_way == -1)
		cub->game->play->pos_y -= PLAYER_SPEED;
	if (cub->game->play->y_way != 0 || cub->game->play->rotate != 0 || cub->game->play->x_way != 0)
	{
		ft_putstr_fd("X = ", 1);
		ft_putnbr_fd(cub->game->play->pos_y, 1);
		ft_putstr_fd("\nY = ", 1);
		ft_putnbr_fd(cub->game->play->pos_x, 1);
		ft_putstr_fd("\n---\n", 1);
		cast_rays(cub);
		mlx_put_image_to_window(cub->game->mlx_p, cub->game->mlx_win ,cub->game->mlx_img, 0, 0);
	}
}

int exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_p, game->mlx_win);
	return 0;
}
