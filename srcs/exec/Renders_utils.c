/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renders_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/08 10:38:17 by fgranger         ###   ########.fr       */
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

int	get_color(t_texture *texture, int x, int y)
{
	int	i;

	i = 0;
	while (texture->key[i] != texture->data[y * texture->width + x])
		i++;
	return (texture->color[i]);
}

double	get_xpm_x(t_texture *t, t_ray *ray)
{
	double	xpm_x;

	if (ray->horizontal == false)
		xpm_x = (int)fmodf((ray->h_x * (t->width / TILE_SIZE)), t->width);
	else
		xpm_x = (int)fmodf((ray->v_y * (t->width / TILE_SIZE)), t->width);
	if (xpm_x < 0)
		xpm_x = 0;
	return (xpm_x);
}
