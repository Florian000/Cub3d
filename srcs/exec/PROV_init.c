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
	char *buff;
	fd = open(path, O_RDONLY);
	if (fd  == -1)
		return (NULL);
	line = get_next_line(fd);
	temp = NULL;
	while (line)
	{
		if (!temp)
		{
			temp = line;
		}
		else
		{
			buff = temp;
			temp = ft_strjoin(temp, line);
			free(buff);
			free(line);
		}
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
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

long custom_hex_to_long(const char *str)
{
    long result;
    int i;
    int sign;
	int	digit;

	i = 0;
	result = 0;
	sign = 1;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-')
	{
        sign = -1;
        i++;
	}
	else if (str[i] == '+')
        i++;
    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
        i += 2;
    while (str[i] != '\0') 
	{
        if (str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            digit = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            digit = str[i] - 'A' + 10;
        else
            break;
        result = result * 16 + digit;
        i++;
    }
    return (result * sign);
}

int init_text(t_texture *t)
{
	int i;
	int j;
	char *temp;
	t_texture *texture;

	i = 4;
	j = 0;
	texture = t;
	texture->lines = get_xpmfile(texture->path);
	if (texture->lines == NULL)
		return (err("Bad malloc / fd"));
	if (ft_strncmp(texture->lines[0], "/* XPM */", 9) != 0)
		return (INVALID);
	get_params(texture);
	while (texture->lines[i]&& ft_strncmp(texture->lines[i], "/* pixels */", 12) != 0)
	{
		texture->color[j] = (int)custom_hex_to_long(texture->lines[i] + 6);
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
	return (VALID);
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

int init_game(t_data *cub)
{
	init_player(cub);
	if (init_text(cub->textures->EA) == INVALID)
		return (INVALID);
	if (init_text(cub->textures->NO) == INVALID)
		return (INVALID);
	if (init_text(cub->textures->WE) == INVALID)
		return (INVALID);
	if (init_text(cub->textures->SO) == INVALID)
		return (INVALID);
	cub->F->color = get_rgb(cub->F->R, cub->F->G, cub->F->B);
	cub->C->color = get_rgb(cub->C->R, cub->C->G, cub->C->B);
	return (VALID);
}