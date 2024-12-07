/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/07 13:47:26 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	stop_ray(float x, float y, t_map *map)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (true);
	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	if (y_m >= map->height || x_m >= map->length)
		return (true);
	if (map->brut_map[y_m] && x_m < ft_strlen(map->brut_map[y_m]))
		if (map->brut_map[y_m][x_m] == '0')
			return (false);
	return (true);
}

void	get_steps(t_player *player, t_ray *ray, float angle, char inter)
{
	if (inter == 'v')
	{
		ray->x_step = TILE_SIZE;
		ray->y_step = fabs(ray->x_step * tan(angle));
		if (angle >= M_PI_2 && angle <= M_PI_2 * 3)
			ray->x_step *= -1;
		if (angle >= M_PI)
			ray->y_step *= -1;
	}
	else if (inter == 'h')
	{
		ray->y_step = TILE_SIZE;
		ray->x_step = fabs(ray->y_step / tan(angle));
		if (angle >= M_PI)
			ray->y_step *= -1;
		if (angle >= M_PI_2 && angle <= M_PI_2 * 3)
			ray->x_step *= -1;
	}
}

void	get_position(t_player *p, t_ray *ray, float angle, char inter)
{
	ray->adjust = 1;
	if (inter == 'v')
	{
		ray->x = floor(p->pos_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		if (angle >= M_PI_2 && angle <= M_PI_2 * 3)
		{
			ray->x = floor(p->pos_x / TILE_SIZE) * TILE_SIZE;
			ray->adjust = -1;
		}
		ray->y = p->pos_y + fabs(((ray->x - p->pos_x) * tan(angle)));
		if (angle >= M_PI)
			ray->y = p->pos_y - fabs(((ray->x - p->pos_x) * tan(angle)));
	}
	else if (inter == 'h')
	{
		ray->y = floor(p->pos_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		if (angle >= M_PI)
			ray->y = floor(p->pos_y / TILE_SIZE) * TILE_SIZE;
		else
			ray->adjust = -1;
		ray->x = p->pos_x + fabs((ray->y - p->pos_y) / tan(angle));
		if (angle >= M_PI_2 && angle <= M_PI_2 * 3)
			ray->x = p->pos_x - fabs((ray->y - p->pos_y) / tan(angle));
	}
}

float	h_inter(t_player *p, t_ray *ray, float angle)
{
	get_steps(p, ray, angle, 'h');
	get_position(p, ray, angle, 'h');
	while (stop_ray(ray->x, ray->y - ray->adjust, p->cub->map) == false)
	{
			ray->x += ray->x_step;
			ray->y += ray->y_step;
	}
	return (sqrt(pow(ray->x - p->pos_x, 2) + pow(ray->y - p->pos_y, 2)));
}

float	v_inter(t_player *p, t_ray *ray, float angle)
{
	get_steps(p, ray, angle, 'v');
	get_position(p, ray, angle, 'v');
	while (stop_ray(ray->x + ray->adjust, ray->y, p->cub->map) == false)
	{
			ray->x += ray->x_step;
			ray->y += ray->y_step;
	}
	return (sqrt(pow(ray->x - p->pos_x, 2) + pow(ray->y - p->pos_y, 2)));
}
