#include "../../include/cub3d.h"

int	inter_check(float angle, float *inter, float *step, int h)
{
	if (h)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE +1;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE + 1;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(float x, float y, t_data *cub)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	//printf("-- xm %d, ym = %d", x_m, y_m);
    if (y_m >= cub->map->hight || x_m >= cub->map->length) 
        return 0;
    if (cub->map->brut_map[y_m] && x_m < (int)strlen(cub->map->brut_map[y_m]))
	{
		if(cub->map->brut_map[y_m][x_m] == '0')
        	return (1);
		printf("wall : %c - x = %d, y= %d px = %f py = %f", cub->map->brut_map[y_m][x_m], x_m, y_m, x, y);
	}
    return (0);
}

int unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle >= 0 && angle <= M_PI)
		return (0);
	}
	else if (c == 'y')
	{
		if (angle >= M_PI_2 && angle <= 3 * M_PI_2)
		return (0);
	}
	return (1);
}

float get_h_inter(t_data *cub, float angl)
{
	float h_x;
	float h_y;
	float x_step;
	float y_step;
	int  first;
	int adjust;
	first = 0;
	y_step = TILE_SIZE;
	if (angl >= M_PI)
	{
		y_step *= -1;
		adjust = 1;
		h_y = floor(cub->game->play->pos_y / TILE_SIZE) * TILE_SIZE;
	}
	else
	{
		h_y = floor(cub->game->play->pos_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		adjust = -1;
	}
	x_step = TILE_SIZE / tan(angl);
	h_x = cub->game->play->pos_x + fabs((h_y - cub->game->play->pos_y) / tan(angl));
	if (angl >= M_PI_2 && angl <= M_PI_2 * 3)
	{
		if (x_step > 0)
			x_step *= -1;
		h_x = cub->game->play->pos_x - fabs((h_y - cub->game->play->pos_y) / tan(angl));
	}
	else if (x_step < 0)
		x_step *= - 1;

	//printf("--HY= %f, hX = %f, x_step = %f y_step = %f  -- ",h_y, h_x, x_step, y_step);
	//printf(" - H : ");
	while (wall_hit(h_x, h_y - adjust, cub))
	{
			h_x += x_step;
			h_y += y_step;
	}
	return (sqrt(pow(h_x - cub->game->play->pos_x, 2) + pow(h_y - cub->game->play->pos_y, 2))); // get the distance
}

float get_v_inter(t_data *cub, float angl)
{
	float v_x;
	float v_y;
	float x_step;
	float y_step;
	int  first;
	int adjust;

	first = 0;
	x_step = TILE_SIZE;
	if (angl <= M_PI_2*3 && angl >= M_PI_2)
	{
		x_step *= -1;
		adjust = -1;
		v_x = floor(cub->game->play->pos_x / TILE_SIZE) * TILE_SIZE;
	}
	else
	{
		v_x = floor(cub->game->play->pos_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		adjust = 1;
	}
	y_step = TILE_SIZE * tan(angl);
	
	v_y = cub->game->play->pos_y + fabs(((v_x - cub->game->play->pos_x) * tan(angl)));
	if (angl >= M_PI)
	{
		if (y_step > 0)
			y_step *= -1;
		v_y = cub->game->play->pos_y - fabs(((v_x - cub->game->play->pos_x) * tan(angl)));
	}
	else if (y_step < 0)
		y_step *= -1;
	else if(v_y < 0)
		v_y *= -1;
	printf("--vY= %f, vX = %f, x_step = %f y_step = %f  --",v_y, v_x, x_step, y_step);
	//printf(" - V : ");
	while (wall_hit(v_x + adjust, v_y, cub))
	{
			v_x += x_step;
			v_y += y_step;
	}
	return (sqrt(pow(v_x - cub->game->play->pos_x, 2) + pow(v_y - cub->game->play->pos_y, 2)));
}

void cast_rays(t_data *cub)
{
    float h_dist;
	float v_dist;
    int ray;

	ray = 0;
	cub->game->ray->ray_ngl = nor_angle(cub->game->play->angle - (cub->game->play->fov / 2));
	printf("pos x = %d, pos y = %d angle = %f\n", cub->game->play->pos_x,cub->game->play->pos_y, cub->game->play->angle);
	while (ray < WIDTH)
	{
		cub->game->ray->horizontal = TRUE;
		h_dist = get_h_inter(cub, nor_angle(cub->game->ray->ray_ngl));
		v_dist = get_v_inter(cub, nor_angle(cub->game->ray->ray_ngl));
		if (v_dist < h_dist)
			cub->game->ray->distance = v_dist;
		else
		{
			cub->game->ray->distance = h_dist;
			cub->game->ray->horizontal = FALSE;
		}
		printf("--Ray %d with angle %f hdist = %f, v_dist = %f\n",ray,cub->game->ray->ray_ngl, h_dist, v_dist);
		render(cub, ray);
		cub->game->ray->ray_ngl += (cub->game->play->fov / WIDTH);
		cub->game->ray->ray_ngl = nor_angle(cub->game->ray->ray_ngl);
		ray ++;
	}
}