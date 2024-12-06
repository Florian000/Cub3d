#include "../../include/cub3d.h"

float nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void cast_rays(t_ray *ray, t_player *player)
{
    float h_dist;
	float v_dist;
    int count_rays;

	count_rays = 0;
	ray->ray_ngl = nor_angle(player->angle - (player->fov / 2));
	while (count_rays < WIDTH)
	{
		ray->horizontal = true;
		h_dist = h_inter(player, ray, nor_angle(ray->ray_ngl));
		v_dist = v_inter(player, ray, nor_angle(ray->ray_ngl));
		if (v_dist < h_dist)
			ray->distance = v_dist;
		else
		{
			ray->distance = h_dist;
			ray->horizontal = false;
		}
		render(ray->cub, count_rays);
		ray->ray_ngl += (player->fov / WIDTH);
		ray->ray_ngl = nor_angle(ray->ray_ngl);
		count_rays++;
	}
}