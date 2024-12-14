/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:36 by fgranger          #+#    #+#             */
/*   Updated: 2024/12/08 21:09:42 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**get_xpmfile(char *path)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*buff;
	char	**lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	temp = line;
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			buff = temp;
			temp = ft_strjoin(temp, line);
			free(buff);
			free(line);
		}
	}
	close(fd);
	lines = ft_split(temp, '\n');
	return (free(line), free(temp), lines);
}

void	get_params(t_texture *t)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(t->lines[3] + 1, ' ');
	t->width = ft_atoi(params[0]);
	t->height = ft_atoi(params[1]);
	t->nb_colors = ft_atoi(params[2]);
	t->key_size = ft_atoi(params[3]);
	t->key = calloc(t->nb_colors, sizeof(int));
	t->color = calloc(t->nb_colors + 1, sizeof(int));
	while (params[i])
		free(params[i++]);
	free(params);
}

int	init_dict(t_texture *t)
{
	int		i;
	int		j;
	int		x;

	i = 4;
	j = 0;
	while (t->lines[i] && ft_strncmp(t->lines[i], "/* pixels */", 12) != 0)
	{
		t->color[j] = (int)custom_hex_to_long(t->lines[i] + 5 + t->key_size);
		x = 0;
		t->key[j] = 0;
		while (x < t->key_size)
		{
			t->key[j] += t->lines[i][x + 1];
			x++;
		}
		j++;
		i++;
	}
	return (i);
}

void	init_text_map(t_texture *t)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = init_dict(t);
	y = 1;
	t->data = ft_calloc(t->width * t->height * t->key_size + 1, sizeof(int));
	if (t->data == NULL)
		exit_game(get_data()->game, "malloc textures 123");
	while (t->lines[++i] && ft_strncmp(t->lines[i], "};", 2) != 0)
	{
		j = 1;
		while (j <= t->width * t->key_size)
		{
			x = -1;
			t->data[y] = 0;
			while (++x < t->key_size)
				t->data[y] += t->lines[i][j + x];
			y++;
			j += t->key_size;
		}
	}
}

int	init_text(t_texture *t)
{
	t->lines = get_xpmfile(t->path);
	if (t->lines == NULL || !t->lines[0])
		exit_game(get_data()->game, "xml file pb");
	if (t->lines[0] && ft_strncmp(t->lines[0], "/* XPM */", 9) != 0)
		exit_game(get_data()->game, " bad xml file");
	get_params(t);
	init_text_map(t);
	return (VALID);
}
