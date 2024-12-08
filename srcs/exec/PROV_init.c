/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROV_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/08 11:26:19 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void init_player(t_data *cub)
{
	cub->game->player->pos_x = cub->map->pos_x * TILE_SIZE + TILE_SIZE / 2;
	cub->game->player->pos_y = cub->map->pos_y * TILE_SIZE + TILE_SIZE / 2;
	cub->game->player->fov = FOV;
	cub->game->player->angle = M_PI_2;
	cub->game->player->cub = cub;
}

char	**get_xpmfile(char *path)
{
	int fd;
	char *line;
	char *temp;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	temp = NULL;
	while (line)
	{
		if (!temp)
			temp = line;
		else
		{
			temp = ft_strjoin(temp, line);
			free(line);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return(ft_split(temp, '\n'));
}

void get_params(t_texture *texture)
{
	char **params;
	params = ft_split(texture->lines[3] + 1, ' ');
	texture->width = ft_atoi(params[0]);
	texture->height = ft_atoi(params[1]);
	texture->nb_colors = ft_atoi(params[2]);
	texture->key = calloc(texture->nb_colors + 1 ,sizeof(char));
	texture->color = calloc(texture->nb_colors + 1, sizeof(int));
}

t_texture *init_text(char *path)
{
	int i;
	int j;
	char *temp;
	t_texture *texture;
	i = 4;
	j = 0;
	texture = calloc(1, sizeof(t_texture));
	texture->path = path;
	texture->lines = get_xpmfile(texture->path);
	if (ft_strncmp(texture->lines[0], "/* XPM */", 9) != 0)
		return ;
	get_params(texture);
	while (texture->lines[i]&& ft_strncmp(texture->lines[i], "/* pixels */", 12) != 0)
	{
		texture->color[j] = (int)strtol(texture->lines[i] + 6, NULL, 16);
		texture->key[j] = texture->lines[i][1];
		j++;
		i++;
	}
	while(texture->lines[++i] && ft_strncmp(texture->lines[i], "};", 2) != 0)
	{
		if (!texture->data)
			texture->data = ft_substr(texture->lines[i], 1, texture->width);
		else
			texture->data = ft_strjoin(texture->data, ft_substr(texture->lines[i], 1, texture->width));
	}
	return (texture);
}

void print_text(t_texture *t)
{
	printf("texture\n");
	printf("height = %d\n",t->height);
	printf("width = %d\n",t->width);
	printf("nb_color = %d\n", t->nb_colors);
	printf("path = %s\n", t->path);

	int i = 0;
	while (i < t->nb_colors)
	{
		printf("%c = %d\n", t->key[i], t->color[i]);
		i++;
	}
	printf("sizemap = %d check = %d", (int)ft_strlen(t->data), t->width * t->height);
	printf("map : %s \n", t->data);
}

int get_rgb(int R, int G, int B)
{
	return ((R << 16) | (G << 8) | B);
}

void init_game(t_data *cub)
{
	init_player(cub);
	cub->textures->EA = init_text("./textures/bricks2.xpm");
	cub->textures->NO = init_text("./textures/bricks2.xpm");
	cub->textures->WE = init_text("./textures/dirt.xpm");
	cub->textures->SO = init_text("./textures/bricks1.xpm");
	cub->F->color = get_rgb(cub->F->R, cub->F->G, cub->F->B);
	cub->C->color = get_rgb(cub->C->R, cub->C->G, cub->C->B);
}