#include "../../include/cub3d.h"

void my_mlx_pixel_put(t_data *cub, int x, int y, int color) // put the pixel
{
	int bpp;
	int size_line;
	int endian;
	int *data = (int *)mlx_get_data_addr(cub->game->mlx_img, &bpp, &size_line, &endian);

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    	data[y * WIDTH + x] = color;
}

float nor_angle(float angle) // normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void draw_floor_ceiling(t_data *cub, int ray, int t_pix, int b_pix) // draw the floor and the ceiling
{
 int  i;
 int  c;

	i = b_pix;
	while (i < HEIGHT)
		my_mlx_pixel_put(cub, ray, i++, 0X00000000);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(cub, ray, i++, 0X000000555);
}

int get_color(t_data *cub, int flag)
{
	if (flag == TRUE)
	{
		if (cub->game->ray->ray_ngl > M_PI / 2 && cub->game->ray->ray_ngl < 3 * (M_PI / 2))
			return (0XFFFFFF); // west wall
		else
			return (0X0000FF); // east wall
	}
	else
	{
		if (cub->game->ray->ray_ngl > 0 && cub->game->ray->ray_ngl < M_PI)
			return (0x00FF00); // south wall
		else
			return (0xFF00); // north wall
	}
}

void draw_wall(t_data *cub, int ray, int t_pix, int b_pix)
{
	int color;

	color = get_color(cub, cub->game->ray->horizontal);
	while (t_pix < b_pix)
		my_mlx_pixel_put(cub, ray, t_pix++, color);
}

void render(t_data *cub, int ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	cub->game->ray->distance *= cos(cub->game->ray->ray_ngl - cub->game->play->angle); // fix the fisheye
	wall_h = (TILE_SIZE / cub->game->ray->distance) * ((WIDTH / 2) / tan(cub->game->play->fov / 2)); // get the wall height
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(cub, ray, t_pix, b_pix);
	draw_floor_ceiling(cub, ray, t_pix, b_pix);
}