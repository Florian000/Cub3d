/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:04:45 by jvittoz           #+#    #+#             */
/*   Updated: 2024/12/08 19:04:47 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//checks there is one argument ending in .cub
void	check_arguments(int argc, char **argv)
{
	int		len;
	char	*temp;

	if (argc != 2)
		exit_game(get_data()->game, "Wrong number of arguments");
	temp = argv[1];
	len = ft_strlen(temp);
	if (len < 4 || ft_strncmp(temp + len - 4, ".cub", 4) != 0)
		exit_game(get_data()->game, "Wrong file extension");
}

int	add_color(char *str)
{
	char	**tab;
	char	**nb;

	tab = ft_split(str, ' ');
	if (!tab || !tab[1])
		return (ft_free2(INVALID, tab));
	nb = ft_split(tab[1], ',');
	if (!nb || check_color(nb) == INVALID)
	{
		ft_free2(INVALID, nb);
		return (ft_free2(INVALID, tab));
	}
	add_color_to_data(nb, tab[0]);
	ft_free2(VALID, nb);
	return (ft_free2(VALID, tab));
}

int	add_first_args(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str + i, "NO ", 3) == VALID
		|| ft_strncmp(str + i, "SO ", 3) == VALID
		|| ft_strncmp(str + i, "WE ", 3) == VALID
		|| ft_strncmp(str + i, "EA ", 3) == VALID)
		return (add_texture(str + i));
	if (ft_strncmp(str + i, "C ", 2) == VALID
		|| ft_strncmp(str + i, "F ", 2) == VALID)
		return (add_color(str + i));
	return (INVALID);
}

int	check_first_args(char *trimmed)
{
	char	*str;

	if (*trimmed && trimmed[0] == '\n')
		return (VALID);
	str = ft_strtrim(trimmed, "\n \t");
	if (ft_strncmp(str, "NO ", 3) == VALID
		|| ft_strncmp(str, "SO ", 3) == VALID
		|| ft_strncmp(str, "WE ", 3) == VALID
		|| ft_strncmp(str, "EA ", 3) == VALID)
	{
		free(str);
		return (VALID);
	}
	if (ft_strncmp(str, "C ", 2) == VALID
		|| ft_strncmp(str, "F ", 2) == VALID)
	{
		free(str);
		return (VALID);
	}
	free(str);
	return (INVALID);
}

int	check_files_open(t_data *data)
{
	t_textures	*t;

	t = data->textures;
	printf("here %s\n", t->ea->path);
	if (open(t->ea->path, O_RDONLY) < 0)
		exit_game(data->game, "path of txt");
	if (open(t->we->path, O_RDONLY) < 0)
		exit_game(data->game, "path of txt");
	if (open(t->no->path, O_RDONLY) < 0)
		exit_game(data->game, "path of txt");
	if (open(t->so->path, O_RDONLY) < 0)
		exit_game(data->game, "path of txt");
	return (VALID);
}
