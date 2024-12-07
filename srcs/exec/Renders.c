/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/07 13:58:23 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(void *mlx_img, int x, int y, int color)
{
	int	bpp;
	int	size_line;
	int	endian;
	int	*data;

	data = (int *)mlx_get_data_addr(mlx_img, &bpp, &size_line, &endian);
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		data[y * WIDTH + x] = color;
}

void	draw_floor_ceiling(t_data *cub, int ray, int t_pix, int b_pix)
{
	int	i;
	int	c;

	i = b_pix;
	while (i < HEIGHT)
		my_mlx_pixel_put(cub->game->mlx_img, ray, i++, 0X00000000);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(cub->game->mlx_img, ray, i++, 0X000000555);
}

int	get_color(t_ray *r, int flag)
{
	if (flag == true)
	{
		if (r->ray_ngl > M_PI / 2 && r->ray_ngl < 3 * (M_PI / 2))
			return (0XFFFFFF);
		else
			return (0X0000FF);
	}
	else
	{
		if (r->ray_ngl > 0 && r->ray_ngl < M_PI)
			return (0x00FF00);
		else
			return (0xFF0000);
	}
}

void	draw_wall(t_data *cub, int ray, int t_pix, int b_pix)
{
	int	color;

	color = get_color(cub->game->ray, cub->game->ray->horizontal);
	while (t_pix < b_pix)
		my_mlx_pixel_put(cub->game->mlx_img, ray, t_pix++, color);
}

void	render(t_ray *r, t_player *p, int count_rays)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	r->distance *= cos(r->ray_ngl - p->angle);
	wall_h = (TILE_SIZE / r->distance) * ((WIDTH / 2) / tan(p->fov / 2));
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(r->cub, count_rays, t_pix, b_pix);
	draw_floor_ceiling(r->cub, count_rays, t_pix, b_pix);
}
