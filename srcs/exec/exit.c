/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/13 20:18:34 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	exit_game(t_game *game, char *str)
{
	if (game->mlx_img)
		mlx_destroy_image(game->mlx_p, game->mlx_img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_p, game->mlx_win);
	if (game->mlx_p)
	{
		mlx_destroy_display(game->mlx_p);
		free(game->mlx_p);
	}
	if (str != NULL)
	{
		ft_putstr_fd(RED, STDERR_FILENO);
		ft_putstr_fd("ERROR : ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd(RST, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (get_data())
		free_data(get_data());
	exit(0);
}
