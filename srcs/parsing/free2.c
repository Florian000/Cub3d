/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:03:50 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/14 18:12:23 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	free_texture(t_texture *t)
{
	if (t->img)
		mlx_destroy_image(t->cub->game->mlx_p, t->img);
	if (t->path)
		free(t->path);
	free(t);
	return (VALID);
}

void	free_mlx(t_game *g)
{
	if (g->mlx_img)
		mlx_destroy_image(g->mlx_p, g->mlx_img);
	if (g->mlx_win)
		mlx_destroy_window(g->mlx_p, g->mlx_win);
	if (g->mlx_p)
	{
		mlx_destroy_display(g->mlx_p);
		free(g->mlx_p);
	}
}
