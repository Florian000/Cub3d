/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/07 20:46:48 by fgranger         ###   ########.fr       */
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
		my_mlx_pixel_put(cub->game->mlx_img, ray, i++, 0X00000000); //modify after parsing with config color
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(cub->game->mlx_img, ray, i++, 0X000000555); //modify after parsing with config color
}

t_texture	*get_texture(t_ray *r, int flag)
{
	if (flag == true)
	{
		if (r->ray_ngl > M_PI / 2 && r->ray_ngl < 3 * (M_PI / 2))
			return (r->cub->textures->EA);
		else
			return (r->cub->textures->WE);
	}
	else
	{
		if (r->ray_ngl > 0 && r->ray_ngl < M_PI)
			return (r->cub->textures->SO);
		else
			return (r->cub->textures->NO);
	}
}

int get_color(t_texture *texture,int x,int y)
{
	int i;
	i = 0;

	while (texture->key[i] != texture->data[y * texture->width + x])
		i++;
	return ((__uint32_t)texture->color[i]);
}

double	get_x_o(t_texture *texture, t_data *cub)
{
	double	x_o;

	if (cub->game->ray->horizontal == false)
		x_o = (int)fmodf((cub->game->ray->h_x * \
		(texture->width / TILE_SIZE)), texture->width);
	else
		x_o = (int)fmodf((cub->game->ray->v_y * \
		(texture->width / TILE_SIZE)), texture->width);
	if (x_o < 0)
		x_o = 0;
	return (x_o);
}

void	draw_wall(t_data *cub, int ray, int t_pix, int b_pix, double wall_h)
{
	t_texture *texture;
	double factor;
	double x_o;
	double y_o;
	
	texture = get_texture(cub->game->ray, cub->game->ray->horizontal);
	
	factor = (double)texture->height / wall_h;
	x_o = get_x_o(texture, cub);
	y_o = (t_pix - (HEIGHT / 2) + (wall_h / 2)) * factor;
	while (t_pix < b_pix)
	{
		if (y_o < 0)
			y_o = 0;
		if (y_o >= texture->height)
			y_o =texture->height -1;
		my_mlx_pixel_put(cub->game->mlx_img, ray, t_pix, get_color(texture, x_o, (int)y_o));
		y_o += factor;
		t_pix++;
	}
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
	draw_wall(r->cub, count_rays, t_pix, b_pix, wall_h);
	draw_floor_ceiling(r->cub, count_rays, t_pix, b_pix);
}
