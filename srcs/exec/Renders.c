/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/08 11:00:19 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_floor_ceiling(t_data *cub, int ray, int ceiling_p, int floor_p)
{
	int	i;
	int	c;

	i = floor_p;
	while (i < HEIGHT)
		my_mlx_pixel_put(cub->game->mlx_img, ray, i++, cub->F->color);
	i = 0;
	while (i < ceiling_p)
		my_mlx_pixel_put(cub->game->mlx_img, ray, i++, cub->C->color);
}

void	draw_wall(t_game *game, int ray, int ceiling_p, int floor_p)
{
	t_texture	*texture;
	double		factor;
	double		xpm_x;
	double		xpm_y;
	int			color;

	texture = get_texture(game->ray, game->ray->horizontal);
	factor = (double)texture->height / game->ray->wall_h;
	xpm_x = get_xpm_x(texture, game->ray);
	xpm_y = (ceiling_p - (HEIGHT / 2) + (game->ray->wall_h / 2)) * factor;
	while (ceiling_p < floor_p)
	{
		if (xpm_y < 0)
			xpm_y = 0;
		if (xpm_y >= texture->height)
			xpm_y = texture->height -1;
		color = get_color(texture, xpm_x, (int)xpm_y);
		my_mlx_pixel_put(game->mlx_img, ray, ceiling_p, color);
		xpm_y += factor;
		ceiling_p++;
	}
}

void	render(t_ray *r, t_player *p, int count_rays)
{
	double	floor_p;
	double	ceiling_p;

	r->distance *= cos(r->ray_ngl - p->angle);
	r->wall_h = (TILE_SIZE / r->distance) * ((WIDTH / 2) / tan(p->fov / 2));
	floor_p = (HEIGHT / 2) + (r->wall_h / 2);
	ceiling_p = (HEIGHT / 2) - (r->wall_h / 2);
	if (floor_p > HEIGHT)
		floor_p = HEIGHT;
	if (ceiling_p < 0)
		ceiling_p = 0;
	draw_wall(r->cub->game, count_rays, ceiling_p, floor_p);
	draw_floor_ceiling(r->cub, count_rays, ceiling_p, floor_p);
}
